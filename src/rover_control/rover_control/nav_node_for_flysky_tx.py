import rclpy
from rclpy.node import Node
from geometry_msgs.msg import TwistStamped
from sensor_msgs.msg import Joy


class NavNode(Node):
    def __init__(self):
        super().__init__('nav_node')

        self.joy_sub = self.create_subscription(
            Joy, 'joy', self.joy_callback, 10)
        self.pd_control_sub = self.create_subscription(
            TwistStamped, 'pd_control/cmd_vel_stamped', self.pd_control_callback, 10)

        self.cmd_vel_pub = self.create_publisher(
            TwistStamped, 'diff_drive_controller/cmd_vel', 10)

        self.mode = "MANUAL"
        self.get_logger().info("NavNode started in MANUAL mode.")
        self.axes = [0.0, 0.0, 0.0, 0.0]
        self.pd_controller_msg = TwistStamped()
        self.timer = self.create_timer(0.1, self.timer_callback)

    def joy_callback(self, msg):
        if len(msg.axes) > 2:
            if msg.axes[2] < 0.0:
                if self.mode != "AUTO":
                    self.get_logger().warn(">>> SWITCHED TO AUTO DRIVE <<<")
                    self.mode = "AUTO"
            elif msg.axes[2] > 0.0:
                if self.mode != "MANUAL":
                    self.get_logger().info(">>> SWITCHED TO MANUAL DRIVE <<<")
                    self.mode = "MANUAL"
        self.axes = msg.axes

    def pd_control_callback(self, msg):
        if self.mode == "AUTO":
            self.pd_controller_msg = msg

    def timer_callback(self):
        msg = TwistStamped()
        if self.mode == "MANUAL":
            msg.header.stamp = self.get_clock().now().to_msg()
            msg.header.frame_id = "base_link"
            msg.twist.linear.x = -self.axes[1]
            msg.twist.angular.z = self.axes[0]
        elif self.mode == "AUTO":
            msg = self.pd_controller_msg
        self.cmd_vel_pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = NavNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
