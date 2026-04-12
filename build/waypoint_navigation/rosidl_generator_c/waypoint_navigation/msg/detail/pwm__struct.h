// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from waypoint_navigation:msg/Pwm.idl
// generated code does not contain a copyright notice

#ifndef WAYPOINT_NAVIGATION__MSG__DETAIL__PWM__STRUCT_H_
#define WAYPOINT_NAVIGATION__MSG__DETAIL__PWM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Pwm in the package waypoint_navigation.
typedef struct waypoint_navigation__msg__Pwm
{
  int32_t pwm_l;
  int32_t pwm_r;
} waypoint_navigation__msg__Pwm;

// Struct for a sequence of waypoint_navigation__msg__Pwm.
typedef struct waypoint_navigation__msg__Pwm__Sequence
{
  waypoint_navigation__msg__Pwm * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} waypoint_navigation__msg__Pwm__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WAYPOINT_NAVIGATION__MSG__DETAIL__PWM__STRUCT_H_
