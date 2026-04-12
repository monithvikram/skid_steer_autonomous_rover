// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from waypoint_navigation:msg/EstimatedOdom.idl
// generated code does not contain a copyright notice

#ifndef WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_ODOM__BUILDER_HPP_
#define WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_ODOM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "waypoint_navigation/msg/detail/estimated_odom__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace waypoint_navigation
{

namespace msg
{

namespace builder
{

class Init_EstimatedOdom_est_odom
{
public:
  Init_EstimatedOdom_est_odom()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::waypoint_navigation::msg::EstimatedOdom est_odom(::waypoint_navigation::msg::EstimatedOdom::_est_odom_type arg)
  {
    msg_.est_odom = std::move(arg);
    return std::move(msg_);
  }

private:
  ::waypoint_navigation::msg::EstimatedOdom msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::waypoint_navigation::msg::EstimatedOdom>()
{
  return waypoint_navigation::msg::builder::Init_EstimatedOdom_est_odom();
}

}  // namespace waypoint_navigation

#endif  // WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_ODOM__BUILDER_HPP_
