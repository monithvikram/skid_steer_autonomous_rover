# Skid Steer Autonomous Rover - ROS2 stack

> Under active development. Pre-v1.0.

---

## What this is

A ROS 2 stack for a 4-wheel skid-steer rover — built from scratch.
No Nav2. No pre-built autonomy packages. Building Custom Nodes.

---

## Stack

- URDF/Xacro — rover model with tuned inertia and wheel-ground friction
- ros2_control — diff_drive_controller + joint_state_broadcaster
- Gazebo — physics simulation
- Custom PD navigation node — rotate then drive, closed loop
- Waypoint action server + client
- Custom odometry node — PWM-based dead reckoning (in progress)
- Data logger — bags odom + cmd_vel to txt

---

## Current progress

- [x] URDF modelled and physics tuned
- [x] Gazebo simulation working
- [x] diff_drive_controller wired and active
- [x] TF chain: odom → base_footprint → base_link → wheels
- [x] Teleop verified
- [x] PD closed loop navigation
- [x] Waypoint action server
- [ ] PWM-based odometry node [ aiming to build it precisely reliable as /diff_drive_controller/odom which reads joint_states from state_interfaces ]
- [ ] Hardware deployment on Jetson Nano
- [ ] ArUco checkpoint navigation
- [ ] IMU fusion for drift correction

---

## Hardware target

- Jetson Nano
- 4x encoderless DC motors
- MPU6050 IMU
- Monocular camera
- 3S LiPo + UBEC power distribution

---

## Why no encoders

Motors available don't have encoders.
Odometry is estimated by mapping PWM output → wheel velocity,
then integrating over time. Manual calibration. Raw engineering.

---

## Status

Simulation setup complete.Building feedforward odom as precise as possible. Hardware deployment next.
