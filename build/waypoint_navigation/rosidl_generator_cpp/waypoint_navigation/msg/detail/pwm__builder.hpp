// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from waypoint_navigation:msg/Pwm.idl
// generated code does not contain a copyright notice

#ifndef WAYPOINT_NAVIGATION__MSG__DETAIL__PWM__BUILDER_HPP_
#define WAYPOINT_NAVIGATION__MSG__DETAIL__PWM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "waypoint_navigation/msg/detail/pwm__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace waypoint_navigation
{

namespace msg
{

namespace builder
{

class Init_Pwm_pwm_r
{
public:
  explicit Init_Pwm_pwm_r(::waypoint_navigation::msg::Pwm & msg)
  : msg_(msg)
  {}
  ::waypoint_navigation::msg::Pwm pwm_r(::waypoint_navigation::msg::Pwm::_pwm_r_type arg)
  {
    msg_.pwm_r = std::move(arg);
    return std::move(msg_);
  }

private:
  ::waypoint_navigation::msg::Pwm msg_;
};

class Init_Pwm_pwm_l
{
public:
  Init_Pwm_pwm_l()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Pwm_pwm_r pwm_l(::waypoint_navigation::msg::Pwm::_pwm_l_type arg)
  {
    msg_.pwm_l = std::move(arg);
    return Init_Pwm_pwm_r(msg_);
  }

private:
  ::waypoint_navigation::msg::Pwm msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::waypoint_navigation::msg::Pwm>()
{
  return waypoint_navigation::msg::builder::Init_Pwm_pwm_l();
}

}  // namespace waypoint_navigation

#endif  // WAYPOINT_NAVIGATION__MSG__DETAIL__PWM__BUILDER_HPP_
