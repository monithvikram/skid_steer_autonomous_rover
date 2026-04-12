// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from waypoint_navigation:msg/Pwm.idl
// generated code does not contain a copyright notice
#include "waypoint_navigation/msg/detail/pwm__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
waypoint_navigation__msg__Pwm__init(waypoint_navigation__msg__Pwm * msg)
{
  if (!msg) {
    return false;
  }
  // pwm_l
  // pwm_r
  return true;
}

void
waypoint_navigation__msg__Pwm__fini(waypoint_navigation__msg__Pwm * msg)
{
  if (!msg) {
    return;
  }
  // pwm_l
  // pwm_r
}

bool
waypoint_navigation__msg__Pwm__are_equal(const waypoint_navigation__msg__Pwm * lhs, const waypoint_navigation__msg__Pwm * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pwm_l
  if (lhs->pwm_l != rhs->pwm_l) {
    return false;
  }
  // pwm_r
  if (lhs->pwm_r != rhs->pwm_r) {
    return false;
  }
  return true;
}

bool
waypoint_navigation__msg__Pwm__copy(
  const waypoint_navigation__msg__Pwm * input,
  waypoint_navigation__msg__Pwm * output)
{
  if (!input || !output) {
    return false;
  }
  // pwm_l
  output->pwm_l = input->pwm_l;
  // pwm_r
  output->pwm_r = input->pwm_r;
  return true;
}

waypoint_navigation__msg__Pwm *
waypoint_navigation__msg__Pwm__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waypoint_navigation__msg__Pwm * msg = (waypoint_navigation__msg__Pwm *)allocator.allocate(sizeof(waypoint_navigation__msg__Pwm), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(waypoint_navigation__msg__Pwm));
  bool success = waypoint_navigation__msg__Pwm__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
waypoint_navigation__msg__Pwm__destroy(waypoint_navigation__msg__Pwm * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    waypoint_navigation__msg__Pwm__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
waypoint_navigation__msg__Pwm__Sequence__init(waypoint_navigation__msg__Pwm__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waypoint_navigation__msg__Pwm * data = NULL;

  if (size) {
    data = (waypoint_navigation__msg__Pwm *)allocator.zero_allocate(size, sizeof(waypoint_navigation__msg__Pwm), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = waypoint_navigation__msg__Pwm__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        waypoint_navigation__msg__Pwm__fini(&data[i - 1]);
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
waypoint_navigation__msg__Pwm__Sequence__fini(waypoint_navigation__msg__Pwm__Sequence * array)
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
      waypoint_navigation__msg__Pwm__fini(&array->data[i]);
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

waypoint_navigation__msg__Pwm__Sequence *
waypoint_navigation__msg__Pwm__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waypoint_navigation__msg__Pwm__Sequence * array = (waypoint_navigation__msg__Pwm__Sequence *)allocator.allocate(sizeof(waypoint_navigation__msg__Pwm__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = waypoint_navigation__msg__Pwm__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
waypoint_navigation__msg__Pwm__Sequence__destroy(waypoint_navigation__msg__Pwm__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    waypoint_navigation__msg__Pwm__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
waypoint_navigation__msg__Pwm__Sequence__are_equal(const waypoint_navigation__msg__Pwm__Sequence * lhs, const waypoint_navigation__msg__Pwm__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!waypoint_navigation__msg__Pwm__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
waypoint_navigation__msg__Pwm__Sequence__copy(
  const waypoint_navigation__msg__Pwm__Sequence * input,
  waypoint_navigation__msg__Pwm__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(waypoint_navigation__msg__Pwm);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    waypoint_navigation__msg__Pwm * data =
      (waypoint_navigation__msg__Pwm *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!waypoint_navigation__msg__Pwm__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          waypoint_navigation__msg__Pwm__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!waypoint_navigation__msg__Pwm__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
