// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from waypoint_navigation:msg/EstimatedTwist.idl
// generated code does not contain a copyright notice

#ifndef WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_TWIST__TRAITS_HPP_
#define WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_TWIST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "waypoint_navigation/msg/detail/estimated_twist__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'est_twist'
#include "geometry_msgs/msg/detail/twist_stamped__traits.hpp"

namespace waypoint_navigation
{

namespace msg
{

inline void to_flow_style_yaml(
  const EstimatedTwist & msg,
  std::ostream & out)
{
  out << "{";
  // member: est_twist
  {
    out << "est_twist: ";
    to_flow_style_yaml(msg.est_twist, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EstimatedTwist & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: est_twist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "est_twist:\n";
    to_block_style_yaml(msg.est_twist, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EstimatedTwist & msg, bool use_flow_style = false)
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
  const waypoint_navigation::msg::EstimatedTwist & msg,
  std::ostream & out, size_t indentation = 0)
{
  waypoint_navigation::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use waypoint_navigation::msg::to_yaml() instead")]]
inline std::string to_yaml(const waypoint_navigation::msg::EstimatedTwist & msg)
{
  return waypoint_navigation::msg::to_yaml(msg);
}

template<>
inline const char * data_type<waypoint_navigation::msg::EstimatedTwist>()
{
  return "waypoint_navigation::msg::EstimatedTwist";
}

template<>
inline const char * name<waypoint_navigation::msg::EstimatedTwist>()
{
  return "waypoint_navigation/msg/EstimatedTwist";
}

template<>
struct has_fixed_size<waypoint_navigation::msg::EstimatedTwist>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::TwistStamped>::value> {};

template<>
struct has_bounded_size<waypoint_navigation::msg::EstimatedTwist>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::TwistStamped>::value> {};

template<>
struct is_message<waypoint_navigation::msg::EstimatedTwist>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_TWIST__TRAITS_HPP_
