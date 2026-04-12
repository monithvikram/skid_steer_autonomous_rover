// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from waypoint_navigation:msg/EstimatedOdom.idl
// generated code does not contain a copyright notice

#ifndef WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_ODOM__TRAITS_HPP_
#define WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_ODOM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "waypoint_navigation/msg/detail/estimated_odom__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'est_odom'
#include "nav_msgs/msg/detail/odometry__traits.hpp"

namespace waypoint_navigation
{

namespace msg
{

inline void to_flow_style_yaml(
  const EstimatedOdom & msg,
  std::ostream & out)
{
  out << "{";
  // member: est_odom
  {
    out << "est_odom: ";
    to_flow_style_yaml(msg.est_odom, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EstimatedOdom & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: est_odom
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "est_odom:\n";
    to_block_style_yaml(msg.est_odom, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EstimatedOdom & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace waypoint_navigation

namespace rosidl_generator_traits
{

[[deprecated("use waypoint_navigation::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const waypoint_navigation::msg::EstimatedOdom & msg,
  std::ostream & out, size_t indentation = 0)
{
  waypoint_navigation::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use waypoint_navigation::msg::to_yaml() instead")]]
inline std::string to_yaml(const waypoint_navigation::msg::EstimatedOdom & msg)
{
  return waypoint_navigation::msg::to_yaml(msg);
}

template<>
inline const char * data_type<waypoint_navigation::msg::EstimatedOdom>()
{
  return "waypoint_navigation::msg::EstimatedOdom";
}

template<>
inline const char * name<waypoint_navigation::msg::EstimatedOdom>()
{
  return "waypoint_navigation/msg/EstimatedOdom";
}

template<>
struct has_fixed_size<waypoint_navigation::msg::EstimatedOdom>
  : std::integral_constant<bool, has_fixed_size<nav_msgs::msg::Odometry>::value> {};

template<>
struct has_bounded_size<waypoint_navigation::msg::EstimatedOdom>
  : std::integral_constant<bool, has_bounded_size<nav_msgs::msg::Odometry>::value> {};

template<>
struct is_message<waypoint_navigation::msg::EstimatedOdom>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_ODOM__TRAITS_HPP_
