#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor

from geometry_msgs.msg import TwistStamped, PoseStamped
from nav_msgs.msg import Odometry
import math
import time

from waypoint_navigation.action import NavToWaypoint


class WayPointServer(Node):
    def __init__(self):
        super().__init__('waypoint_server')

        self.goal_x = 0.0
        self.goal_y = 0.0

        self.x = 0.0
        self.y = 0.0
        self.theta = 0.0
        self.prev_distance = 0.0
        self.Kp_linear = 3.0
        self.Kd_linear = 0.2
        self.Kp_angular = 5.0
        self.Kd_angular = 0.1
        self.prev_angle_error = 0.0

        self.prev_time = time.time()

        self.action_callback_group = ReentrantCallbackGroup()
        self.odom_callback_group = ReentrantCallbackGroup()

        self.publisher_ = self.create_publisher(
            TwistStamped, '/diff_drive_controller/cmd_vel', 10)
        self.odom_sub = self.create_subscription(
            Odometry, '/diff_drive_controller/odom', self.odom_callback, 10,
            callback_group=self.odom_callback_group)

        self.action_server = ActionServer(
            self,
            NavToWaypoint,
            'waypoint_navigation',
            self.execute_callback,
            callback_group=self.action_callback_group
        )

        self.get_logger().info('Waypoint Action Server ready.')

    def odom_callback(self, msg):
        self.x = msg.pose.pose.position.x
        self.y = msg.pose.pose.position.y
        q = msg.pose.pose.orientation
        self.theta = math.atan2(
            2 * (q.w * q.z + q.x * q.y),
            1 - 2 * (q.y * q.y + q.z * q.z))

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')

        self.goal_x = goal_handle.request.waypoint.position.x
        self.goal_y = goal_handle.request.waypoint.position.y

        self.get_logger().info(
            f'New Waypoint Set: ({self.goal_x}, {self.goal_y})')

        feedback_msg = NavToWaypoint.Feedback()

        rate = self.create_rate(60)  # 30 Hz control loop

        while rclpy.ok():
            dx = self.goal_x - self.x
            dy = self.goal_y - self.y
            distance = math.sqrt(dx**2 + dy**2)
            distance_error = distance - self.prev_distance
            # Publish feedback
            feedback_msg.current_position = PoseStamped()
            feedback_msg.current_position.pose.position.x = self.x
            feedback_msg.current_position.pose.position.y = self.y
            goal_handle.publish_feedback(feedback_msg)

            if distance < 0.06:
                self.stop_robot()
                self.get_logger().info('Goal reached.')
                break

            angle_error = math.atan2(
                math.sin(math.atan2(dy, dx) - self.theta),
                math.cos(math.atan2(dy, dx) - self.theta))

            start_time = time.time()
            dt = start_time - self.prev_time

            d_angle_error = (angle_error - self.prev_angle_error) / dt
            self.prev_angle_error = angle_error

            msg = TwistStamped()
            msg.header.stamp = self.get_clock().now().to_msg()
            msg.header.frame_id = "base_link"
            msg.twist.linear.x = min(
                self.Kp_linear * distance + (self.Kd_linear * distance_error) / dt, 1.0) if abs(angle_error) < 0.1 else 0.0
            msg.twist.angular.z = max(min(
                self.Kp_angular * angle_error + self.Kd_angular * d_angle_error,
                1.5), -1.5)
            self.publisher_.publish(msg)
            self.prev_distance = distance
            self.prev_time = start_time

            rate.sleep()

        goal_handle.succeed()

        result = NavToWaypoint.Result()
        result.travel_time = int(time.time() - start_time)
        return result

    def stop_robot(self):
        msg = TwistStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        self.publisher_.publish(msg)


def main(args=None):
    rclpy.init(args=args)

    waypoint_server = WayPointServer()
    executor = MultiThreadedExecutor()
    executor.add_node(waypoint_server)

    try:
        executor.spin()
    except KeyboardInterrupt:
        waypoint_server.get_logger().info('KeyboardInterrupt, shutting down.\n')
    finally:
        waypoint_server.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
