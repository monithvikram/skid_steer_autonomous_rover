// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from waypoint_navigation:msg/EstimatedOdom.idl
// generated code does not contain a copyright notice

#ifndef WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_ODOM__FUNCTIONS_H_
#define WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_ODOM__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "waypoint_navigation/msg/rosidl_generator_c__visibility_control.h"

#include "waypoint_navigation/msg/detail/estimated_odom__struct.h"

/// Initialize msg/EstimatedOdom message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * waypoint_navigation__msg__EstimatedOdom
 * )) before or use
 * waypoint_navigation__msg__EstimatedOdom__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_waypoint_navigation
bool
waypoint_navigation__msg__EstimatedOdom__init(waypoint_navigation__msg__EstimatedOdom * msg);

/// Finalize msg/EstimatedOdom message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_waypoint_navigation
void
waypoint_navigation__msg__EstimatedOdom__fini(waypoint_navigation__msg__EstimatedOdom * msg);

/// Create msg/EstimatedOdom message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * waypoint_navigation__msg__EstimatedOdom__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_waypoint_navigation
waypoint_navigation__msg__EstimatedOdom *
waypoint_navigation__msg__EstimatedOdom__create();

/// Destroy msg/EstimatedOdom message.
/**
 * It calls
 * waypoint_navigation__msg__EstimatedOdom__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_waypoint_navigation
void
waypoint_navigation__msg__EstimatedOdom__destroy(waypoint_navigation__msg__EstimatedOdom * msg);

/// Check for msg/EstimatedOdom message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_waypoint_navigation
bool
waypoint_navigation__msg__EstimatedOdom__are_equal(const waypoint_navigation__msg__EstimatedOdom * lhs, const waypoint_navigation__msg__EstimatedOdom * rhs);

/// Copy a msg/EstimatedOdom message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_waypoint_navigation
bool
waypoint_navigation__msg__EstimatedOdom__copy(
  const waypoint_navigation__msg__EstimatedOdom * input,
  waypoint_navigation__msg__EstimatedOdom * output);

/// Initialize array of msg/EstimatedOdom messages.
/**
 * It allocates the memory for the number of elements and calls
 * waypoint_navigation__msg__EstimatedOdom__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_waypoint_navigation
bool
waypoint_navigation__msg__EstimatedOdom__Sequence__init(waypoint_navigation__msg__EstimatedOdom__Sequence * array, size_t size);

/// Finalize array of msg/EstimatedOdom messages.
/**
 * It calls
 * waypoint_navigation__msg__EstimatedOdom__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_waypoint_navigation
void
waypoint_navigation__msg__EstimatedOdom__Sequence__fini(waypoint_navigation__msg__EstimatedOdom__Sequence * array);

/// Create array of msg/EstimatedOdom messages.
/**
 * It allocates the memory for the array and calls
 * waypoint_navigation__msg__EstimatedOdom__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_waypoint_navigation
waypoint_navigation__msg__EstimatedOdom__Sequence *
waypoint_navigation__msg__EstimatedOdom__Sequence__create(size_t size);

/// Destroy array of msg/EstimatedOdom messages.
/**
 * It calls
 * waypoint_navigation__msg__EstimatedOdom__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_waypoint_navigation
void
waypoint_navigation__msg__EstimatedOdom__Sequence__destroy(waypoint_navigation__msg__EstimatedOdom__Sequence * array);

/// Check for msg/EstimatedOdom message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_waypoint_navigation
bool
waypoint_navigation__msg__EstimatedOdom__Sequence__are_equal(const waypoint_navigation__msg__EstimatedOdom__Sequence * lhs, const waypoint_navigation__msg__EstimatedOdom__Sequence * rhs);

/// Copy an array of msg/EstimatedOdom messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_waypoint_navigation
bool
waypoint_navigation__msg__EstimatedOdom__Sequence__copy(
  const waypoint_navigation__msg__EstimatedOdom__Sequence * input,
  waypoint_navigation__msg__EstimatedOdom__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // WAYPOINT_NAVIGATION__MSG__DETAIL__ESTIMATED_ODOM__FUNCTIONS_H_
