// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from waypoint_navigation:msg/Pwm.idl
// generated code does not contain a copyright notice

#ifndef WAYPOINT_NAVIGATION__MSG__DETAIL__PWM__STRUCT_HPP_
#define WAYPOINT_NAVIGATION__MSG__DETAIL__PWM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__waypoint_navigation__msg__Pwm __attribute__((deprecated))
#else
# define DEPRECATED__waypoint_navigation__msg__Pwm __declspec(deprecated)
#endif

namespace waypoint_navigation
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Pwm_
{
  using Type = Pwm_<ContainerAllocator>;

  explicit Pwm_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pwm_l = 0l;
      this->pwm_r = 0l;
    }
  }

  explicit Pwm_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pwm_l = 0l;
      this->pwm_r = 0l;
    }
  }

  // field types and members
  using _pwm_l_type =
    int32_t;
  _pwm_l_type pwm_l;
  using _pwm_r_type =
    int32_t;
  _pwm_r_type pwm_r;

  // setters for named parameter idiom
  Type & set__pwm_l(
    const int32_t & _arg)
  {
    this->pwm_l = _arg;
    return *this;
  }
  Type & set__pwm_r(
    const int32_t & _arg)
  {
    this->pwm_r = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    waypoint_navigation::msg::Pwm_<ContainerAllocator> *;
  using ConstRawPtr =
    const waypoint_navigation::msg::Pwm_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<waypoint_navigation::msg::Pwm_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<waypoint_navigation::msg::Pwm_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      waypoint_navigation::msg::Pwm_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<waypoint_navigation::msg::Pwm_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      waypoint_navigation::msg::Pwm_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<waypoint_navigation::msg::Pwm_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<waypoint_navigation::msg::Pwm_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<waypoint_navigation::msg::Pwm_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__waypoint_navigation__msg__Pwm
    std::shared_ptr<waypoint_navigation::msg::Pwm_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__waypoint_navigation__msg__Pwm
    std::shared_ptr<waypoint_navigation::msg::Pwm_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Pwm_ & other) const
  {
    if (this->pwm_l != other.pwm_l) {
      return false;
    }
    if (this->pwm_r != other.pwm_r) {
      return false;
    }
    return true;
  }
  bool operator!=(const Pwm_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Pwm_

// alias to use template instance with default allocator
using Pwm =
  waypoint_navigation::msg::Pwm_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace waypoint_navigation

#endif  // WAYPOINT_NAVIGATION__MSG__DETAIL__PWM__STRUCT_HPP_
