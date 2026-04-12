// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from waypoint_navigation:msg/EstimatedOdom.idl
// generated code does not contain a copyright notice

#ifndef WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_ODOM__STRUCT_H_
#define WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_ODOM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'est_odom'
#include "nav_msgs/msg/detail/odometry__struct.h"

/// Struct defined in msg/EstimatedOdom in the package waypoint_navigation.
typedef struct waypoint_navigation__msg__EstimatedOdom
{
  nav_msgs__msg__Odometry est_odom;
} waypoint_navigation__msg__EstimatedOdom;

// Struct for a sequence of waypoint_navigation__msg__EstimatedOdom.
typedef struct waypoint_navigation__msg__EstimatedOdom__Sequence
{
  waypoint_navigation__msg__EstimatedOdom * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} waypoint_navigation__msg__EstimatedOdom__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_ODOM__STRUCT_H_
