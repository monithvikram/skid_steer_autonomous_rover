from sensor_msgs.msg import JointState
from nav_msgs.msg import Odometry
import math
from rclpy.node import Node
import rclpy


class OdomValidator(Node):
    def __init__(self):
        super().__init__('odom_validator')

        self.wheel_separation = 0.41
        self.wheel_radius = 0.0625

        self.x = 0.0
        self.y = 0.0
        self.heading = 0.0
        self.last_time = self.get_clock().now()

        # joint names — match your URDF exactly
        self.rl_joint = 'rl_joint'
        self.rr_joint = 'rr_joint'
        self.fl_joint = 'fl_joint'
        self.fr_joint = 'fr_joint'

        # Gazebo gives angular velocity (rad/s), store last values
        self.omega_l = 0.0
        self.omega_r = 0.0

        self.create_subscription(
            JointState, '/joint_states', self.joint_cb, 10)
        self.odom_pub = self.create_publisher(
            Odometry, '/estimated_odom', 10)
        self.create_timer(0.02, self.timer_callback)  # 20Hz

    def joint_cb(self, msg: JointState):
        for i, name in enumerate(msg.name):
            if name == self.rl_joint:
                self.omega_l = msg.velocity[i]
            elif name == self.rr_joint:
                self.omega_r = msg.velocity[i]
        self.get_logger().info(f'L: {self.omega_l:.3f}  R: {self.omega_r:.3f}')

    def timer_callback(self):
        now = self.get_clock().now()
        dt = (now - self.last_time).nanoseconds * 1e-9
        self.last_time = now
        if dt < 1e-6:
            return

        # wheel surface velocity → displacement
        vl = self.omega_l * self.wheel_radius
        vr = self.omega_r * self.wheel_radius

        dl = vl * dt
        dr = vr * dt

        linear = (dl + dr) * 0.5
        angular = (dr - dl) / self.wheel_separation

        self._integrate_exact(linear, angular)

        odom = Odometry()
        odom.header.stamp = now.to_msg()
        odom.header.frame_id = "odom"
        odom.child_frame_id = "base_link"

        odom.pose.pose.position.x = self.x
        odom.pose.pose.position.y = self.y
        odom.pose.pose.orientation.z = math.sin(self.heading / 2.0)
        odom.pose.pose.orientation.w = math.cos(self.heading / 2.0)

        odom.twist.twist.linear.x = linear / dt
        odom.twist.twist.angular.z = angular / dt
        odom.pose.covariance = self._diag_covariance(0.01)
        odom.twist.covariance = self._diag_covariance(0.01)
        self.odom_pub.publish(odom)

    def _integrate_exact(self, linear: float, angular: float):
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
    node = OdomValidator()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
