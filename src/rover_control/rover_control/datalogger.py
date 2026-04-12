#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import TwistStamped
import time


class DataLogger(Node):
    def __init__(self):
        super().__init__('data_logger')

        timestamp = time.strftime("%Y%m%d_%H%M%S")
        self.log_file = open(f'rover_log_{timestamp}.txt', 'w')
        self.log_file.write("time,odom_x,odom_y,odom_theta,linear_x,angular_z\n")

        self.odom_x = 0.0
        self.odom_y = 0.0
        self.odom_theta = 0.0
        self.linear_x = 0.0
        self.angular_z = 0.0

        self.create_subscription(
            Odometry,
            '/diff_drive_controller/odom',
            self.odom_callback, 10)

        self.create_subscription(
            TwistStamped,
            '/diff_drive_controller/cmd_vel',
            self.cmd_callback, 10)

        self.create_timer(0.1, self.log_callback)
        self.get_logger().info(f'Logging to rover_log_{timestamp}.txt')

    def odom_callback(self, msg):
        self.odom_x = msg.pose.pose.position.x
        self.odom_y = msg.pose.pose.position.y
        q = msg.pose.pose.orientation
        import math
        self.odom_theta = math.atan2(
            2 * (q.w * q.z + q.x * q.y),
            1 - 2 * (q.y * q.y + q.z * q.z))

    def cmd_callback(self, msg):
        self.linear_x = msg.twist.linear.x
        self.angular_z = msg.twist.angular.z

    def log_callback(self):
        t = self.get_clock().now().nanoseconds / 1e9
        line = f"{t:.3f},{self.odom_x:.4f},{self.odom_y:.4f},{self.odom_theta:.4f},{self.linear_x:.4f},{self.angular_z:.4f}\n"
        self.log_file.write(line)
        self.log_file.flush()

    def destroy_node(self):
        self.log_file.close()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = DataLogger()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()