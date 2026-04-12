// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from waypoint_navigation:srv/GetWayPoints.idl
// generated code does not contain a copyright notice

#ifndef WAYPOINT_NAVIGATION__SRV__DETAIL__GET_WAY_POINTS__BUILDER_HPP_
#define WAYPOINT_NAVIGATION__SRV__DETAIL__GET_WAY_POINTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "waypoint_navigation/srv/detail/get_way_points__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace waypoint_navigation
{

namespace srv
{

namespace builder
{

class Init_GetWayPoints_Request_get_waypoints
{
public:
  Init_GetWayPoints_Request_get_waypoints()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::waypoint_navigation::srv::GetWayPoints_Request get_waypoints(::waypoint_navigation::srv::GetWayPoints_Request::_get_waypoints_type arg)
  {
    msg_.get_waypoints = std::move(arg);
    return std::move(msg_);
  }

private:
  ::waypoint_navigation::srv::GetWayPoints_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::waypoint_navigation::srv::GetWayPoints_Request>()
{
  return waypoint_navigation::srv::builder::Init_GetWayPoints_Request_get_waypoints();
}

}  // namespace waypoint_navigation


namespace waypoint_navigation
{

namespace srv
{

namespace builder
{

class Init_GetWayPoints_Response_waypoints
{
public:
  Init_GetWayPoints_Response_waypoints()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::waypoint_navigation::srv::GetWayPoints_Response waypoints(::waypoint_navigation::srv::GetWayPoints_Response::_waypoints_type arg)
  {
    msg_.waypoints = std::move(arg);
    return std::move(msg_);
  }

private:
  ::waypoint_navigation::srv::GetWayPoints_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::waypoint_navigation::srv::GetWayPoints_Response>()
{
  return waypoint_navigation::srv::builder::Init_GetWayPoints_Response_waypoints();
}

}  // namespace waypoint_navigation

#endif  // WAYPOINT_NAVIGATION__SRV__DETAIL__GET_WAY_POINTS__BUILDER_HPP_
