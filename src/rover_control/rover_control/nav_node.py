import sys
import tty
import termios
import threading

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import TwistStamped


class NavNode(Node):
    def __init__(self):
        super().__init__('nav_node')

        self.teleop_sub = self.create_subscription(
            TwistStamped, '/telsd/cmd_vel', self.teleop_callback, 10)
        self.pd_control_sub = self.create_subscription(
            TwistStamped, 'pd_control/cmd_vel_stamped', self.pd_control_callback, 10)

        self.cmd_vel_pub = self.create_publisher(
            TwistStamped, 'diff_drive_controller/cmd_vel', 10)

        self.mode = "MANUAL"
        self.teleop_msg = TwistStamped()
        self.pd_msg = TwistStamped()

        self.get_logger().info("NavNode started in MANUAL mode. Press Ctrl+A to toggle.")

        self.timer = self.create_timer(0.1, self.timer_callback)

        # Keyboard listener in a daemon thread
        self._kb_thread = threading.Thread(
            target=self._keyboard_listener, daemon=True)
        self._kb_thread.start()

    def _keyboard_listener(self):
        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)
        try:
            tty.setraw(fd)
            while rclpy.ok():
                ch = sys.stdin.read(1)
                if ch == '\x01':  # Ctrl+A
                    if self.mode == "MANUAL":
                        self.mode = "AUTO"
                        self.get_logger().warn(">>> SWITCHED TO AUTO DRIVE <<<")
                    else:
                        self.mode = "MANUAL"
                        self.get_logger().info(">>> SWITCHED TO MANUAL DRIVE <<<")
                elif ch == '\x03':  # Ctrl+C — graceful exit
                    break
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)

    def teleop_callback(self, msg: TwistStamped):
        self.teleop_msg = msg

    def pd_control_callback(self, msg: TwistStamped):
        self.pd_msg = msg

    def timer_callback(self):
        if self.mode == "MANUAL":
            out = TwistStamped()
            out.header.stamp = self.get_clock().now().to_msg()
            out.header.frame_id = "base_footprint"
            out.twist = self.teleop_msg.twist
            self.cmd_vel_pub.publish(out)
        else:
            self.cmd_vel_pub.publish(self.pd_msg)


def main(args=None):
    rclpy.init(args=args)
    node = NavNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
