// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from waypoint_navigation:msg/EstimatedTwist.idl
// generated code does not contain a copyright notice

#ifndef WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_TWIST__STRUCT_HPP_
#define WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_TWIST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'est_twist'
#include "geometry_msgs/msg/detail/twist_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__waypoint_navigation__msg__EstimatedTwist __attribute__((deprecated))
#else
# define DEPRECATED__waypoint_navigation__msg__EstimatedTwist __declspec(deprecated)
#endif

namespace waypoint_navigation
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EstimatedTwist_
{
  using Type = EstimatedTwist_<ContainerAllocator>;

  explicit EstimatedTwist_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : est_twist(_init)
  {
    (void)_init;
  }

  explicit EstimatedTwist_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : est_twist(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _est_twist_type =
    geometry_msgs::msg::TwistStamped_<ContainerAllocator>;
  _est_twist_type est_twist;

  // setters for named parameter idiom
  Type & set__est_twist(
    const geometry_msgs::msg::TwistStamped_<ContainerAllocator> & _arg)
  {
    this->est_twist = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    waypoint_navigation::msg::EstimatedTwist_<ContainerAllocator> *;
  using ConstRawPtr =
    const waypoint_navigation::msg::EstimatedTwist_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<waypoint_navigation::msg::EstimatedTwist_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<waypoint_navigation::msg::EstimatedTwist_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      waypoint_navigation::msg::EstimatedTwist_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<waypoint_navigation::msg::EstimatedTwist_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      waypoint_navigation::msg::EstimatedTwist_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<waypoint_navigation::msg::EstimatedTwist_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<waypoint_navigation::msg::EstimatedTwist_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<waypoint_navigation::msg::EstimatedTwist_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__waypoint_navigation__msg__EstimatedTwist
    std::shared_ptr<waypoint_navigation::msg::EstimatedTwist_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__waypoint_navigation__msg__EstimatedTwist
    std::shared_ptr<waypoint_navigation::msg::EstimatedTwist_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EstimatedTwist_ & other) const
  {
    if (this->est_twist != other.est_twist) {
      return false;
    }
    return true;
  }
  bool operator!=(const EstimatedTwist_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EstimatedTwist_

// alias to use template instance with default allocator
using EstimatedTwist =
  waypoint_navigation::msg::EstimatedTwist_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace waypoint_navigation

#endif  // WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_TWIST__STRUCT_HPP_
