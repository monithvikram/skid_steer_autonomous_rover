// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from waypoint_navigation:msg/EstimatedTwist.idl
// generated code does not contain a copyright notice

#ifndef WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_TWIST__STRUCT_H_
#define WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_TWIST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'est_twist'
#include "geometry_msgs/msg/detail/twist_stamped__struct.h"

/// Struct defined in msg/EstimatedTwist in the package waypoint_navigation.
typedef struct waypoint_navigation__msg__EstimatedTwist
{
  geometry_msgs__msg__TwistStamped est_twist;
} waypoint_navigation__msg__EstimatedTwist;

// Struct for a sequence of waypoint_navigation__msg__EstimatedTwist.
typedef struct waypoint_navigation__msg__EstimatedTwist__Sequence
{
  waypoint_navigation__msg__EstimatedTwist * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} waypoint_navigation__msg__EstimatedTwist__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_TWIST__STRUCT_H_
