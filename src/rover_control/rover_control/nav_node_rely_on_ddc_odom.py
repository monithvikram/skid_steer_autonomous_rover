import rclpy
from rclpy.node import Node
from geometry_msgs.msg import TwistStamped
from nav_msgs.msg import Odometry
import math


class NavNode(Node):
    def __init__(self):
        super().__init__('nav_node')

        self.goal_x = 1.0
        self.goal_y = 0.0

        self.x = 0.0
        self.y = 0.0
        self.theta = 0.0

        self.Kp_linear = 0.5
        self.Kd_linear = 0.1
        self.Kp_angular = 2.0
        self.Kd_angular = 0.2
        self.prev_angle_error = 0.0
        self.prev_distance = 0.0

        self.publisher_ = self.create_publisher(
            TwistStamped, '/diff_drive_controller/cmd_vel', 10)
        self.odom_sub = self.create_subscription(
            Odometry, '/diff_drive_controller/odom', self.odom_callback, 10)
        self.timer = self.create_timer(0.1, self.control_loop)
        self.get_logger().info('NavNode ready.')

    def odom_callback(self, msg):
        self.x = msg.pose.pose.position.x
        self.y = msg.pose.pose.position.y
        q = msg.pose.pose.orientation
        self.theta = math.atan2(
            2 * (q.w * q.z + q.x * q.y),
            1 - 2 * (q.y * q.y + q.z * q.z))

    def control_loop(self):
        dx = self.goal_x - self.x
        dy = self.goal_y - self.y
        distance = math.sqrt(dx**2 + dy**2)
        distance_error = distance - self.prev_distance
        if distance < 0.1:
            self.stop_robot()
            self.get_logger().info('Goal reached.')
            return

        angle_error = math.atan2(
            math.sin(math.atan2(dy, dx) - self.theta),
            math.cos(math.atan2(dy, dx) - self.theta))

        d_angle_error = (angle_error - self.prev_angle_error) / 0.1
        self.prev_angle_error = angle_error

        msg = TwistStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "base_link"
        msg.twist.linear.x = min(
            self.Kp_linear * distance + (self.Kd_linear * distance_error) / 0.1, 0.6) if angle_error < 0.1 else 0.0
        msg.twist.angular.z = max(min(
            self.Kp_angular * angle_error + self.Kd_angular * d_angle_error,
            1.0), -1.0)
        self.publisher_.publish(msg)

    def stop_robot(self):
        msg = TwistStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        self.publisher_.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = NavNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
