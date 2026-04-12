import rclpy
from rclpy.node import Node
import math
from collections import deque
from geometry_msgs.msg import TwistStamped
from nav_msgs.msg import Odometry
from waypoint_navigation.msg import Pwm


class RollingMean:
    """Mirrors the RollingMeanAccumulator in the C++ diff_drive_controller."""

    def __init__(self, window_size: int):
        self.window = deque(maxlen=window_size)

    def accumulate(self, value: float):
        self.window.append(value)

    def mean(self) -> float:
        return sum(self.window) / len(self.window) if self.window else 0.0


class PwmToOdomEstimator(Node):
    def __init__(self):
        super().__init__('pwm_to_odom_estimator')

        # --- params ---
        self.wheel_separation = 0.4075
        VELOCITY_WINDOW = 10   # tune: larger = smoother but laggier

        # --- state ---
        self.x = 0.0
        self.y = 0.0

        self.max_velocity = 1.0
        self.max_angular_velocity = 1.5
        # kept as raw angle, never serialized directly
        self.heading = 0.0
        self.last_time = self.get_clock().now()

        # --- velocity smoothers (mirrors C++ rolling accumulators) ---
        self.linear_acc = RollingMean(VELOCITY_WINDOW)
        self.angular_acc = RollingMean(VELOCITY_WINDOW)

        # --- ROS I/O ---
        self.pwm_msg = Pwm()
        self.pwm_sub = self.create_subscription(
            Pwm, '/pwm', self.pwm_callback, 10)
        self.twist_pub = self.create_publisher(
            TwistStamped, 'estimated_twist', 10)
        self.odom_pub = self.create_publisher(Odometry, 'estimated_odom', 10)
        self.create_timer(0.1, self.timer_callback)

    # ------------------------------------------------------------------
    def pwm_callback(self, msg: Pwm):
        self.pwm_msg = msg

    # ------------------------------------------------------------------
    def timer_callback(self):
        now = self.get_clock().now()
        dt = (now - self.last_time).nanoseconds * 1e-9
        self.last_time = now

        if dt < 1e-4:
            return   # guard: too small to integrate

        # --- PWM → wheel velocities (m/s) ---
        ul = (self.pwm_msg.pwm_l - 1500) / 300.0
        ur = (self.pwm_msg.pwm_r - 1500) / 300.0

        # displacement this tick (mirrors C++ update() → updateFromVelocity())
        dl = ul * self.max_velocity * dt
        dr = ur * self.max_velocity * dt

        linear = (dl + dr) * 0.5
        angular = (dr - dl) / self.wheel_separation

        # --- integrate pose (exact arc, mirrors integrateExact) ---
        self._integrate_exact(linear, angular)

        # --- smooth velocities (mirrors rolling accumulator) ---
        # self.linear_acc.accumulate(linear / dt)
        # self.angular_acc.accumulate(angular / dt)
        # vx = self.linear_acc.mean()
        # omegaz = self.angular_acc.mean()

        vx = linear / dt
        omegaz = angular / dt

        # --- publish TwistStamped ---
        twist = TwistStamped()
        twist.header.stamp = now.to_msg()
        twist.header.frame_id = "base_link"
        twist.twist.linear.x = vx
        twist.twist.angular.z = omegaz
        self.twist_pub.publish(twist)

        # --- publish Odometry ---
        odom = Odometry()
        odom.header.stamp = now.to_msg()
        odom.header.frame_id = "odom"
        odom.child_frame_id = "base_link"

        odom.pose.pose.position.x = self.x
        odom.pose.pose.position.y = self.y
        odom.pose.pose.position.z = 0.0

        # quaternion from yaw — only z and w matter for a planar robot
        odom.pose.pose.orientation.z = math.sin(self.heading / 2.0)
        odom.pose.pose.orientation.w = math.cos(self.heading / 2.0)

        # twist in child frame (base_link)
        odom.twist.twist.linear.x = vx
        odom.twist.twist.angular.z = omegaz

        odom.pose.covariance = self._diag_covariance(0.01)
        odom.twist.covariance = self._diag_covariance(0.01)

        self.odom_pub.publish(odom)

    # ------------------------------------------------------------------
    def _integrate_exact(self, linear: float, angular: float):
        """
        Mirrors diff_drive_controller::Odometry::integrateExact().
        Treats motion as a true circular arc — much lower error on curves
        than Euler integration.
        """
        if abs(angular) < 1e-3:
            # Near-straight: Runge-Kutta 2nd order (midpoint method)
            # mirrors integrateRungeKutta2()
            direction = self.heading + angular * 0.5
            self.x += linear * math.cos(direction)
            self.y += linear * math.sin(direction)
            self.heading += angular
        else:
            # Exact arc integration
            heading_old = self.heading
            r = linear / angular          # turning radius
            self.heading += angular
            self.x += r * (math.sin(self.heading) - math.sin(heading_old))
            self.y += -r * (math.cos(self.heading) - math.cos(heading_old))

        # keep heading in [-π, π]
        self.heading = math.atan2(
            math.sin(self.heading), math.cos(self.heading))

    # ------------------------------------------------------------------
    @staticmethod
    def _diag_covariance(diag_val: float) -> list:
        """6×6 diagonal covariance, row-major."""
        cov = [0.0] * 36
        for i in range(6):
            cov[i * 6 + i] = diag_val
        return cov


def main(args=None):
    rclpy.init(args=args)
    node = PwmToOdomEstimator()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
