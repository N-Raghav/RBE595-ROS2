// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from franka_control:srv/PandaSrv.idl
// generated code does not contain a copyright notice
#include "franka_control/srv/detail/panda_srv__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "franka_control/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "franka_control/srv/detail/panda_srv__struct.h"
#include "franka_control/srv/detail/panda_srv__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/float64_multi_array__functions.h"  // grasps

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_control
size_t get_serialized_size_std_msgs__msg__Float64MultiArray(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_control
size_t max_serialized_size_std_msgs__msg__Float64MultiArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_control
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Float64MultiArray)();


using _PandaSrv_Request__ros_msg_type = franka_control__srv__PandaSrv_Request;

static bool _PandaSrv_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PandaSrv_Request__ros_msg_type * ros_message = static_cast<const _PandaSrv_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: grasps
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float64MultiArray
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->grasps, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _PandaSrv_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PandaSrv_Request__ros_msg_type * ros_message = static_cast<_PandaSrv_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: grasps
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float64MultiArray
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->grasps))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_control
size_t get_serialized_size_franka_control__srv__PandaSrv_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PandaSrv_Request__ros_msg_type * ros_message = static_cast<const _PandaSrv_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name grasps

  current_alignment += get_serialized_size_std_msgs__msg__Float64MultiArray(
    &(ros_message->grasps), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _PandaSrv_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_franka_control__srv__PandaSrv_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_control
size_t max_serialized_size_franka_control__srv__PandaSrv_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: grasps
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Float64MultiArray(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = franka_control__srv__PandaSrv_Request;
    is_plain =
      (
      offsetof(DataType, grasps) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _PandaSrv_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_franka_control__srv__PandaSrv_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PandaSrv_Request = {
  "franka_control::srv",
  "PandaSrv_Request",
  _PandaSrv_Request__cdr_serialize,
  _PandaSrv_Request__cdr_deserialize,
  _PandaSrv_Request__get_serialized_size,
  _PandaSrv_Request__max_serialized_size
};

static rosidl_message_type_support_t _PandaSrv_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PandaSrv_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_control, srv, PandaSrv_Request)() {
  return &_PandaSrv_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "franka_control/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "franka_control/srv/detail/panda_srv__struct.h"
// already included above
// #include "franka_control/srv/detail/panda_srv__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/float64__functions.h"  // flag

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_control
size_t get_serialized_size_std_msgs__msg__Float64(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_control
size_t max_serialized_size_std_msgs__msg__Float64(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_control
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Float64)();


using _PandaSrv_Response__ros_msg_type = franka_control__srv__PandaSrv_Response;

static bool _PandaSrv_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PandaSrv_Response__ros_msg_type * ros_message = static_cast<const _PandaSrv_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: flag
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float64
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->flag, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _PandaSrv_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PandaSrv_Response__ros_msg_type * ros_message = static_cast<_PandaSrv_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: flag
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float64
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->flag))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_control
size_t get_serialized_size_franka_control__srv__PandaSrv_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PandaSrv_Response__ros_msg_type * ros_message = static_cast<const _PandaSrv_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name flag

  current_alignment += get_serialized_size_std_msgs__msg__Float64(
    &(ros_message->flag), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _PandaSrv_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_franka_control__srv__PandaSrv_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_control
size_t max_serialized_size_franka_control__srv__PandaSrv_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: flag
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Float64(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = franka_control__srv__PandaSrv_Response;
    is_plain =
      (
      offsetof(DataType, flag) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _PandaSrv_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_franka_control__srv__PandaSrv_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PandaSrv_Response = {
  "franka_control::srv",
  "PandaSrv_Response",
  _PandaSrv_Response__cdr_serialize,
  _PandaSrv_Response__cdr_deserialize,
  _PandaSrv_Response__get_serialized_size,
  _PandaSrv_Response__max_serialized_size
};

static rosidl_message_type_support_t _PandaSrv_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PandaSrv_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_control, srv, PandaSrv_Response)() {
  return &_PandaSrv_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "franka_control/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "franka_control/srv/panda_srv.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t PandaSrv__callbacks = {
  "franka_control::srv",
  "PandaSrv",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_control, srv, PandaSrv_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_control, srv, PandaSrv_Response)(),
};

static rosidl_service_type_support_t PandaSrv__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &PandaSrv__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_control, srv, PandaSrv)() {
  return &PandaSrv__handle;
}

#if defined(__cplusplus)
}
#endif
