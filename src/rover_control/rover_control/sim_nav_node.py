import rclpy
from rclpy.node import Node
from geometry_msgs.msg import TwistStamped
from nav_msgs.msg import Odometry
import math

# THIS NODE IS TO PUBLISH CMD_VEL USING DIFF_DRIVE_CONTROLLER IN SIM
# BUT USE FEEDFORWARD BASED ON THE LIVE_PWM_MSG PUBLISHED BY THE PWM_NODE
# IN SIM , LIVE_PWM_MSG IS NOT AVAILABLE , IN REAL ,USE THE PWM_NODE TO PUBLISH PWM VALUES DIRECTLY TO THE ESC IN REAL BOT
# IN U CAN USE PID CONTROLLER TO PUBLISH CMD_VEL USING DIFF_DRIVE_CONTROLLER
# IN REAL , U HAVE TO CALIBRATE THE RELATION BETWEEN LIVE PWM AND THE BOTS VELOCITY BY USING IMU DATA AND LIVE PWM TO SEE THE RELATION.
# THEN, USE THE RELATION TO PUBLISH PWM USING LIVE_PWM_MSG TO YOUR MICROCONTROLLER


class PwmSimNavNode(Node):
    def __init__(self):
        super().__init__('pwm_sim_nav_node')

        self.goal_x = 2.0
        self.goal_y = 2.0

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
            Odometry, '/estimated_odom', self.odom_callback, 10)
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

    # IF U SIMULATE, THEN USE THIS TO PUBLISH CMD_VEL USING DIFF_DRIVE_CONTROLLER,
    # WHICH HAS ACCESS TO COMMAND INTERFACE [velocity of joints] OF THE SIMULATED ROBOT
    # ELSE USE THE PWM_NODE TO PUBLISH PWM VALUES DIRECTLY TO THE ESC IN REAL BOT

    def pub_cmd_vel(self):
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

    def timer_callback(self):
        vl = (self.live_pwm_msg.pwm_l - 1500.0) / 200.0
        vr = (self.live_pwm_msg.pwm_r - 1500.0) / 200.0
        v = (vl + vr) / 2.0
        omega = (vr - vl) / 0.4075
        self.est_twist_msg.twist.linear.x = v
        self.est_twist_msg.twist.angular.z = omega
        self.est_twist_pub.publish(self.est_twist_msg)


def main(args=None):
    rclpy.init(args=args)
    pwm_sim_nav_node = PwmSimNavNode()
    rclpy.spin(pwm_sim_nav_node)
    pwm_sim_nav_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
