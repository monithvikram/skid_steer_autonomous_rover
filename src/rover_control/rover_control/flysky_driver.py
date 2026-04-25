import rclpy
from rclpy.node import Node
from geometry_msgs.msg import TwistStamped
from sensor_msgs.msg import Joy


class FlyskyDriver(Node):
    def __init__(self):
        super().__init__('flysky_driver')
        self.cmd_vel_publisher_ = self.create_publisher(
            TwistStamped, 'flysky_driver/cmd_vel_stamped', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)
        self.joy_sub = self.create_subscription(
            Joy, '/joy', self.joy_callback, 10)
        self.axes = [0.0, 0.0, 0.0, 0.0]

    def joy_callback(self, msg):
        self.axes = msg.axes

    def timer_callback(self):
        msg = TwistStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "base_link"
        msg.twist.linear.x = self.axes[1]
        msg.twist.angular.z = self.axes[0]
        self.cmd_vel_publisher_.publish(msg)

        self.get_logger().info(
            f'Linear velocity: {msg.twist.linear.x}, Angular velocity: {msg.twist.angular.z}')


def main(args=None):
    rclpy.init(args=args)
    flysky_driver = FlyskyDriver()
    rclpy.spin(flysky_driver)
    flysky_driver.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
