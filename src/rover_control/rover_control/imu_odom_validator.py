from sensor_msgs.msg import JointState, Imu
from nav_msgs.msg import Odometry
import math
from rclpy.node import Node
import rclpy
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped


class ImuOdomValidator(Node):
    def __init__(self):
        super().__init__('imu_odom_validator')

        self.wheel_separation = 0.41
        self.wheel_radius = 0.0625

        self.x = 0.0
        self.y = 0.0
        self.heading = 0.0
        self.last_time = self.get_clock().now()

        self.omega_l = 0.0
        self.omega_r = 0.0
        self.angular_velocity = 0.0

        self.fl_joint = 'fl_joint'
        self.fr_joint = 'fr_joint'
        self.rl_joint = 'rl_joint'
        self.rr_joint = 'rr_joint'

        self.create_subscription(
            JointState, '/joint_states', self.joint_cb, 10)
        self.create_subscription(
            Imu,        '/imu/data',    self.imu_cb,   100)
        self.odom_pub = self.create_publisher(
            Odometry, '/imu_estimated_odom', 10)
        self.create_timer(0.01, self.timer_callback)  # 100Hz

        self.tf_broadcaster = TransformBroadcaster(self)

    def imu_cb(self, msg: Imu):
        self.angular_velocity = msg.angular_velocity.z

    def joint_cb(self, msg: JointState):
        self.omega_l = 0.0
        self.omega_r = 0.0
        for i, name in enumerate(msg.name):
            if name == self.fl_joint:
                self.omega_l += msg.velocity[i]
            elif name == self.rl_joint:
                self.omega_l += msg.velocity[i]
            elif name == self.fr_joint:
                self.omega_r += msg.velocity[i]
            elif name == self.rr_joint:
                self.omega_r += msg.velocity[i]
        self.omega_l /= 2
        self.omega_r /= 2

    def timer_callback(self):
        now = self.get_clock().now()
        dt = (now - self.last_time).nanoseconds * 1e-9
        self.last_time = now
        if dt < 1e-4:
            return

        vl = self.omega_l * self.wheel_radius
        vr = self.omega_r * self.wheel_radius

        dl = vl * dt
        dr = vr * dt

        linear = (dl + dr) * 0.5
        angular = self.angular_velocity * dt
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
        odom.twist.twist.angular.z = self.angular_velocity if abs(
            self.angular_velocity) > 0.1 else 0.0

        odom.pose.covariance = self._diag_covariance(0.01)
        odom.twist.covariance = self._diag_covariance(0.01)
        self.odom_pub.publish(odom)

        t = TransformStamped()
        t.header.stamp = now.to_msg()
        t.header.frame_id = "odom"
        t.child_frame_id = "base_footprint"

        t.transform.translation.x = self.x
        t.transform.translation.y = self.y
        t.transform.translation.z = 0.0
        t.transform.rotation.z = math.sin(self.heading / 2.0)
        t.transform.rotation.w = math.cos(self.heading / 2.0)

        self.tf_broadcaster.sendTransform(t)

    def _integrate_exact(self, linear: float, angular: float):
        if abs(angular) < 1e-3:
            direction = self.heading + angular * 0.5
            self.x += linear * math.cos(direction)
            self.y += linear * math.sin(direction)
            self.heading += angular
        else:
            heading_old = self.heading
            r = linear / angular
            self.heading += angular
            self.x += r * (math.sin(self.heading) - math.sin(heading_old))
            self.y += -r * (math.cos(self.heading) - math.cos(heading_old))

        self.heading = math.atan2(
            math.sin(self.heading), math.cos(self.heading))

    @staticmethod
    def _diag_covariance(v):
        cov = [0.0] * 36
        for i in range(6):
            cov[i * 6 + i] = v
        return cov


def main(args=None):
    rclpy.init(args=args)
    rclpy.spin(ImuOdomValidator())


if __name__ == '__main__':
    main()
