// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from waypoint_navigation:msg/EstimatedOdom.idl
// generated code does not contain a copyright notice

#ifndef WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_ODOM__STRUCT_HPP_
#define WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_ODOM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'est_odom'
#include "nav_msgs/msg/detail/odometry__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__waypoint_navigation__msg__EstimatedOdom __attribute__((deprecated))
#else
# define DEPRECATED__waypoint_navigation__msg__EstimatedOdom __declspec(deprecated)
#endif

namespace waypoint_navigation
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EstimatedOdom_
{
  using Type = EstimatedOdom_<ContainerAllocator>;

  explicit EstimatedOdom_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : est_odom(_init)
  {
    (void)_init;
  }

  explicit EstimatedOdom_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : est_odom(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _est_odom_type =
    nav_msgs::msg::Odometry_<ContainerAllocator>;
  _est_odom_type est_odom;

  // setters for named parameter idiom
  Type & set__est_odom(
    const nav_msgs::msg::Odometry_<ContainerAllocator> & _arg)
  {
    this->est_odom = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    waypoint_navigation::msg::EstimatedOdom_<ContainerAllocator> *;
  using ConstRawPtr =
    const waypoint_navigation::msg::EstimatedOdom_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<waypoint_navigation::msg::EstimatedOdom_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<waypoint_navigation::msg::EstimatedOdom_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      waypoint_navigation::msg::EstimatedOdom_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<waypoint_navigation::msg::EstimatedOdom_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      waypoint_navigation::msg::EstimatedOdom_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<waypoint_navigation::msg::EstimatedOdom_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<waypoint_navigation::msg::EstimatedOdom_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<waypoint_navigation::msg::EstimatedOdom_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__waypoint_navigation__msg__EstimatedOdom
    std::shared_ptr<waypoint_navigation::msg::EstimatedOdom_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__waypoint_navigation__msg__EstimatedOdom
    std::shared_ptr<waypoint_navigation::msg::EstimatedOdom_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EstimatedOdom_ & other) const
  {
    if (this->est_odom != other.est_odom) {
      return false;
    }
    return true;
  }
  bool operator!=(const EstimatedOdom_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EstimatedOdom_

// alias to use template instance with default allocator
using EstimatedOdom =
  waypoint_navigation::msg::EstimatedOdom_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace waypoint_navigation

#endif  // WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_ODOM__STRUCT_HPP_
