#!/usr/bin/env python3

import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node

from waypoint_navigation.action import NavToWaypoint


class WayPointClient(Node):
    def __init__(self):
        super().__init__('waypoint_client')

        # self.goals = [
        #     [2.0, 0.0],
        #     [0.0, 0.0],

        # ]

        self.goals = [[3.0, 0.0], [3.0, 3.0], [0.0, 3.0], [0.0, 0.0]]

        # self.goals = [[0.5, 0.5], [0.5, 0.5], [0.0, 0.0]]

        # self.goals = [
        #     [3.0, 0.0],
        #     [4.0, 3.0],
        #     [0.0, 3.0],
        #     [-2.0, -2.0],
        #     [0.0, 0.0],
        # ]

        # self.goals = [
        #     [4.0, 0.0],
        #     [0.0, 0.0],

        # ]

        # self.goals = [
        #     [2.0, 2.0],
        #     [0.0, 0.0],

        # ]

        # self.goals = [
        #     [2.0, 0.0],
        #     [2.0, -2.0],
        #     [0.0, -2.0],
        #     [0.0, 0.0],

        # ]
        self.goal_index = 0
        self.action_client = ActionClient(
            self, NavToWaypoint, 'waypoint_navigation')

    def send_goal(self, waypoint):
        goal_msg = NavToWaypoint.Goal()
        goal_msg.waypoint.position.x = waypoint[0]
        goal_msg.waypoint.position.y = waypoint[1]
        goal_msg.waypoint.position.z = 0.0

        self.get_logger().info('Waiting for action server...')
        self.action_client.wait_for_server()

        self.get_logger().info(
            f'Sending goal ({waypoint[0]}, {waypoint[1]})...')
        self.send_goal_future = self.action_client.send_goal_async(
            goal_msg, feedback_callback=self.feedback_callback)
        self.send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return

        self.get_logger().info('Goal accepted :)')
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info('Goal Reached!')
        self.get_logger().info(
            'Travel Time: {0} seconds'.format(result.travel_time))

        self.goal_index += 1

        if self.goal_index < len(self.goals):
            self.send_goal(self.goals[self.goal_index])
        else:
            self.get_logger().info('All waypoints have been reached successfully')
            rclpy.shutdown()

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        x = feedback.current_position.pose.position.x
        y = feedback.current_position.pose.position.y
        self.get_logger().info(
            f'Current goal ({self.goals[self.goal_index][0]}, {self.goals[self.goal_index][1]})')
        self.get_logger().info(
            f'Feedback -> Current Position: ({x:.2f}, {y:.2f})')


def main(args=None):
    rclpy.init(args=args)

    waypoint_client = WayPointClient()

    if len(waypoint_client.goals) > 0:
        waypoint_client.send_goal(waypoint_client.goals[0])
    try:
        rclpy.spin(waypoint_client)
    except KeyboardInterrupt:
        waypoint_client.get_logger().info('KeyboardInterrupt, shutting down.\n')
    finally:
        if rclpy.ok():
            waypoint_client.destroy_node()
            rclpy.shutdown()


if __name__ == '__main__':
    main()
