// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from waypoint_navigation:msg/EstimatedTwist.idl
// generated code does not contain a copyright notice
#include "waypoint_navigation/msg/detail/estimated_twist__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `est_twist`
#include "geometry_msgs/msg/detail/twist_stamped__functions.h"

bool
waypoint_navigation__msg__EstimatedTwist__init(waypoint_navigation__msg__EstimatedTwist * msg)
{
  if (!msg) {
    return false;
  }
  // est_twist
  if (!geometry_msgs__msg__TwistStamped__init(&msg->est_twist)) {
    waypoint_navigation__msg__EstimatedTwist__fini(msg);
    return false;
  }
  return true;
}

void
waypoint_navigation__msg__EstimatedTwist__fini(waypoint_navigation__msg__EstimatedTwist * msg)
{
  if (!msg) {
    return;
  }
  // est_twist
  geometry_msgs__msg__TwistStamped__fini(&msg->est_twist);
}

bool
waypoint_navigation__msg__EstimatedTwist__are_equal(const waypoint_navigation__msg__EstimatedTwist * lhs, const waypoint_navigation__msg__EstimatedTwist * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // est_twist
  if (!geometry_msgs__msg__TwistStamped__are_equal(
      &(lhs->est_twist), &(rhs->est_twist)))
  {
    return false;
  }
  return true;
}

bool
waypoint_navigation__msg__EstimatedTwist__copy(
  const waypoint_navigation__msg__EstimatedTwist * input,
  waypoint_navigation__msg__EstimatedTwist * output)
{
  if (!input || !output) {
    return false;
  }
  // est_twist
  if (!geometry_msgs__msg__TwistStamped__copy(
      &(input->est_twist), &(output->est_twist)))
  {
    return false;
  }
  return true;
}

waypoint_navigation__msg__EstimatedTwist *
waypoint_navigation__msg__EstimatedTwist__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waypoint_navigation__msg__EstimatedTwist * msg = (waypoint_navigation__msg__EstimatedTwist *)allocator.allocate(sizeof(waypoint_navigation__msg__EstimatedTwist), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(waypoint_navigation__msg__EstimatedTwist));
  bool success = waypoint_navigation__msg__EstimatedTwist__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
waypoint_navigation__msg__EstimatedTwist__destroy(waypoint_navigation__msg__EstimatedTwist * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    waypoint_navigation__msg__EstimatedTwist__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
waypoint_navigation__msg__EstimatedTwist__Sequence__init(waypoint_navigation__msg__EstimatedTwist__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waypoint_navigation__msg__EstimatedTwist * data = NULL;

  if (size) {
    data = (waypoint_navigation__msg__EstimatedTwist *)allocator.zero_allocate(size, sizeof(waypoint_navigation__msg__EstimatedTwist), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = waypoint_navigation__msg__EstimatedTwist__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        waypoint_navigation__msg__EstimatedTwist__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
waypoint_navigation__msg__EstimatedTwist__Sequence__fini(waypoint_navigation__msg__EstimatedTwist__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      waypoint_navigation__msg__EstimatedTwist__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

waypoint_navigation__msg__EstimatedTwist__Sequence *
waypoint_navigation__msg__EstimatedTwist__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waypoint_navigation__msg__EstimatedTwist__Sequence * array = (waypoint_navigation__msg__EstimatedTwist__Sequence *)allocator.allocate(sizeof(waypoint_navigation__msg__EstimatedTwist__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = waypoint_navigation__msg__EstimatedTwist__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
waypoint_navigation__msg__EstimatedTwist__Sequence__destroy(waypoint_navigation__msg__EstimatedTwist__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    waypoint_navigation__msg__EstimatedTwist__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
waypoint_navigation__msg__EstimatedTwist__Sequence__are_equal(const waypoint_navigation__msg__EstimatedTwist__Sequence * lhs, const waypoint_navigation__msg__EstimatedTwist__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!waypoint_navigation__msg__EstimatedTwist__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
waypoint_navigation__msg__EstimatedTwist__Sequence__copy(
  const waypoint_navigation__msg__EstimatedTwist__Sequence * input,
  waypoint_navigation__msg__EstimatedTwist__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(waypoint_navigation__msg__EstimatedTwist);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    waypoint_navigation__msg__EstimatedTwist * data =
      (waypoint_navigation__msg__EstimatedTwist *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!waypoint_navigation__msg__EstimatedTwist__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          waypoint_navigation__msg__EstimatedTwist__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!waypoint_navigation__msg__EstimatedTwist__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
