// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from waypoint_navigation:srv/GetWayPoints.idl
// generated code does not contain a copyright notice

#ifndef WAYPOINT_NAVIGATION__SRV__DETAIL__GET_WAY_POINTS__STRUCT_H_
#define WAYPOINT_NAVIGATION__SRV__DETAIL__GET_WAY_POINTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetWayPoints in the package waypoint_navigation.
typedef struct waypoint_navigation__srv__GetWayPoints_Request
{
  bool get_waypoints;
} waypoint_navigation__srv__GetWayPoints_Request;

// Struct for a sequence of waypoint_navigation__srv__GetWayPoints_Request.
typedef struct waypoint_navigation__srv__GetWayPoints_Request__Sequence
{
  waypoint_navigation__srv__GetWayPoints_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} waypoint_navigation__srv__GetWayPoints_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'waypoints'
#include "geometry_msgs/msg/detail/pose_array__struct.h"

/// Struct defined in srv/GetWayPoints in the package waypoint_navigation.
typedef struct waypoint_navigation__srv__GetWayPoints_Response
{
  geometry_msgs__msg__PoseArray waypoints;
} waypoint_navigation__srv__GetWayPoints_Response;

// Struct for a sequence of waypoint_navigation__srv__GetWayPoints_Response.
typedef struct waypoint_navigation__srv__GetWayPoints_Response__Sequence
{
  waypoint_navigation__srv__GetWayPoints_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} waypoint_navigation__srv__GetWayPoints_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WAYPOINT_NAVIGATION__SRV__DETAIL__GET_WAY_POINTS__STRUCT_H_
