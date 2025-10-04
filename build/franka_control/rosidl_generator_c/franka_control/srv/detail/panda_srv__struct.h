// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from franka_control:srv/PandaSrv.idl
// generated code does not contain a copyright notice

#ifndef FRANKA_CONTROL__SRV__DETAIL__PANDA_SRV__STRUCT_H_
#define FRANKA_CONTROL__SRV__DETAIL__PANDA_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'grasps'
#include "std_msgs/msg/detail/float64_multi_array__struct.h"

/// Struct defined in srv/PandaSrv in the package franka_control.
typedef struct franka_control__srv__PandaSrv_Request
{
  /// Flattened grasps. each grasp has x y z angle width label
  std_msgs__msg__Float64MultiArray grasps;
} franka_control__srv__PandaSrv_Request;

// Struct for a sequence of franka_control__srv__PandaSrv_Request.
typedef struct franka_control__srv__PandaSrv_Request__Sequence
{
  franka_control__srv__PandaSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_control__srv__PandaSrv_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'flag'
#include "std_msgs/msg/detail/float64__struct.h"

/// Struct defined in srv/PandaSrv in the package franka_control.
typedef struct franka_control__srv__PandaSrv_Response
{
  std_msgs__msg__Float64 flag;
} franka_control__srv__PandaSrv_Response;

// Struct for a sequence of franka_control__srv__PandaSrv_Response.
typedef struct franka_control__srv__PandaSrv_Response__Sequence
{
  franka_control__srv__PandaSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_control__srv__PandaSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FRANKA_CONTROL__SRV__DETAIL__PANDA_SRV__STRUCT_H_
