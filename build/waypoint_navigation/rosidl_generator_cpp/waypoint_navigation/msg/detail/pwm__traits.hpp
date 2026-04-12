// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from waypoint_navigation:msg/Pwm.idl
// generated code does not contain a copyright notice

#ifndef WAYPOINT_NAVIGATION__MSG__DETAIL__PWM__TRAITS_HPP_
#define WAYPOINT_NAVIGATION__MSG__DETAIL__PWM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "waypoint_navigation/msg/detail/pwm__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace waypoint_navigation
{

namespace msg
{

inline void to_flow_style_yaml(
  const Pwm & msg,
  std::ostream & out)
{
  out << "{";
  // member: pwm_l
  {
    out << "pwm_l: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm_l, out);
    out << ", ";
  }

  // member: pwm_r
  {
    out << "pwm_r: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm_r, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Pwm & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pwm_l
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pwm_l: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm_l, out);
    out << "\n";
  }

  // member: pwm_r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pwm_r: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm_r, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Pwm & msg, bool use_flow_style = false)
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
  const waypoint_navigation::msg::Pwm & msg,
  std::ostream & out, size_t indentation = 0)
{
  waypoint_navigation::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use waypoint_navigation::msg::to_yaml() instead")]]
inline std::string to_yaml(const waypoint_navigation::msg::Pwm & msg)
{
  return waypoint_navigation::msg::to_yaml(msg);
}

template<>
inline const char * data_type<waypoint_navigation::msg::Pwm>()
{
  return "waypoint_navigation::msg::Pwm";
}

template<>
inline const char * name<waypoint_navigation::msg::Pwm>()
{
  return "waypoint_navigation/msg/Pwm";
}

template<>
struct has_fixed_size<waypoint_navigation::msg::Pwm>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<waypoint_navigation::msg::Pwm>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<waypoint_navigation::msg::Pwm>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WAYPOINT_NAVIGATION__MSG__DETAIL__PWM__TRAITS_HPP_
