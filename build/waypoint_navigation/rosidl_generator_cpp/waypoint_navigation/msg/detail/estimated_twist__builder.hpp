// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from waypoint_navigation:msg/EstimatedTwist.idl
// generated code does not contain a copyright notice

#ifndef WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_TWIST__BUILDER_HPP_
#define WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_TWIST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "waypoint_navigation/msg/detail/estimated_twist__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace waypoint_navigation
{

namespace msg
{

namespace builder
{

class Init_EstimatedTwist_est_twist
{
public:
  Init_EstimatedTwist_est_twist()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::waypoint_navigation::msg::EstimatedTwist est_twist(::waypoint_navigation::msg::EstimatedTwist::_est_twist_type arg)
  {
    msg_.est_twist = std::move(arg);
    return std::move(msg_);
  }

private:
  ::waypoint_navigation::msg::EstimatedTwist msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::waypoint_navigation::msg::EstimatedTwist>()
{
  return waypoint_navigation::msg::builder::Init_EstimatedTwist_est_twist();
}

}  // namespace waypoint_navigation

#endif  // WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_TWIST__BUILDER_HPP_
