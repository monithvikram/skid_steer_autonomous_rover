import rclpy
import math
from geometry_msgs.msg import TwistStamped
from waypoint_navigation.msg import Pwm
from rclpy.node import Node
#  THIS IS USEFUL ONLY IF U TEST THE PWM TO ODOM PIPELINE USING TELEOP

# WHAT HAPPENED: I STOPPED THE PD CONTROLLER, YET THE ODOM IS PUBLISHE AS PWM IS A CONSTANT , AND I TRACKED THE PAST SOURCE, I CANT FIGURE HOW IT WAS STOREED N CONTINUSKLY PUBLISHED.


class TeleopToPwm(Node):
    def __init__(self):
        super().__init__('teleop_to_pwm')
        self.cmd_vel_sub = self.create_subscription(
            TwistStamped,
            '/diff_drive_controller/cmd_vel',
            self.twist_callback,
            10)
        self.pwm_pub = self.create_publisher(Pwm, '/pwm', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)
        self.twist_msg = TwistStamped()

        self.wheel_seperation = 0.4075
        self.prev_pwm_l = 1500
        self.prev_pwm_r = 1500

        self.max_velocity = 1.0
        self.max_angular_velocity = 1.5

    def twist_callback(self, msg):
        self.twist_msg = msg

    def apply_slew(self, current, target, max_step):
        """
        Gradually moves current value toward target value by a fixed maximum step.
        """
        error = target - current

        # If the change is smaller than our max_step, just jump to target
        if abs(error) <= max_step:
            return target

        # Otherwise, move only by the max_step in the direction of the error
        # math.copysign returns max_step with the sign of the error (+ or -)
        return current + int(math.copysign(max_step, error))

    def timer_callback(self):
        # 1. Calculate ideal targets from Twist (Inverse Kinematics)
        vl = self.twist_msg.twist.linear.x - \
            self.twist_msg.twist.angular.z * self.wheel_seperation / 2
        vr = self.twist_msg.twist.linear.x + \
            self.twist_msg.twist.angular.z * self.wheel_seperation / 2

        ul = vl / self.max_velocity
        ur = vr / self.max_velocity

        target_pwm_l = int(1500 + ul * 300)
        target_pwm_r = int(1500 + ur * 300)

        # 2. Apply Slew Rate to each wheel independently
        # For a 10Hz timer (0.1s), a max_step of 15-20 is realistic for geared motors
        ramp_l = self.apply_slew(self.prev_pwm_l, target_pwm_l, max_step=15)
        ramp_r = self.apply_slew(self.prev_pwm_r, target_pwm_r, max_step=15)

        # 3. Create message and update state
        msg = Pwm()
        msg.pwm_l = ramp_l
        msg.pwm_r = ramp_r

        self.prev_pwm_l = ramp_l
        self.prev_pwm_r = ramp_r

        self.pwm_pub.publish(msg)
        self.get_logger().info(
            f'PWM: {msg.pwm_l}, {msg.pwm_r} Vel: {self.twist_msg.twist.linear.x}, {self.twist_msg.twist.angular.z}')


def main(args=None):
    rclpy.init(args=args)
    teleop_to_pwm = TeleopToPwm()
    rclpy.spin(teleop_to_pwm)
    teleop_to_pwm.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
