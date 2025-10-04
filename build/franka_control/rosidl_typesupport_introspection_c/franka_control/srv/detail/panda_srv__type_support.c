// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from franka_control:srv/PandaSrv.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "franka_control/srv/detail/panda_srv__rosidl_typesupport_introspection_c.h"
#include "franka_control/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "franka_control/srv/detail/panda_srv__functions.h"
#include "franka_control/srv/detail/panda_srv__struct.h"


// Include directives for member types
// Member `grasps`
#include "std_msgs/msg/float64_multi_array.h"
// Member `grasps`
#include "std_msgs/msg/detail/float64_multi_array__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void franka_control__srv__PandaSrv_Request__rosidl_typesupport_introspection_c__PandaSrv_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  franka_control__srv__PandaSrv_Request__init(message_memory);
}

void franka_control__srv__PandaSrv_Request__rosidl_typesupport_introspection_c__PandaSrv_Request_fini_function(void * message_memory)
{
  franka_control__srv__PandaSrv_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember franka_control__srv__PandaSrv_Request__rosidl_typesupport_introspection_c__PandaSrv_Request_message_member_array[1] = {
  {
    "grasps",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(franka_control__srv__PandaSrv_Request, grasps),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers franka_control__srv__PandaSrv_Request__rosidl_typesupport_introspection_c__PandaSrv_Request_message_members = {
  "franka_control__srv",  // message namespace
  "PandaSrv_Request",  // message name
  1,  // number of fields
  sizeof(franka_control__srv__PandaSrv_Request),
  franka_control__srv__PandaSrv_Request__rosidl_typesupport_introspection_c__PandaSrv_Request_message_member_array,  // message members
  franka_control__srv__PandaSrv_Request__rosidl_typesupport_introspection_c__PandaSrv_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  franka_control__srv__PandaSrv_Request__rosidl_typesupport_introspection_c__PandaSrv_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t franka_control__srv__PandaSrv_Request__rosidl_typesupport_introspection_c__PandaSrv_Request_message_type_support_handle = {
  0,
  &franka_control__srv__PandaSrv_Request__rosidl_typesupport_introspection_c__PandaSrv_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_franka_control
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_control, srv, PandaSrv_Request)() {
  franka_control__srv__PandaSrv_Request__rosidl_typesupport_introspection_c__PandaSrv_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Float64MultiArray)();
  if (!franka_control__srv__PandaSrv_Request__rosidl_typesupport_introspection_c__PandaSrv_Request_message_type_support_handle.typesupport_identifier) {
    franka_control__srv__PandaSrv_Request__rosidl_typesupport_introspection_c__PandaSrv_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &franka_control__srv__PandaSrv_Request__rosidl_typesupport_introspection_c__PandaSrv_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "franka_control/srv/detail/panda_srv__rosidl_typesupport_introspection_c.h"
// already included above
// #include "franka_control/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "franka_control/srv/detail/panda_srv__functions.h"
// already included above
// #include "franka_control/srv/detail/panda_srv__struct.h"


// Include directives for member types
// Member `flag`
#include "std_msgs/msg/float64.h"
// Member `flag`
#include "std_msgs/msg/detail/float64__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void franka_control__srv__PandaSrv_Response__rosidl_typesupport_introspection_c__PandaSrv_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  franka_control__srv__PandaSrv_Response__init(message_memory);
}

void franka_control__srv__PandaSrv_Response__rosidl_typesupport_introspection_c__PandaSrv_Response_fini_function(void * message_memory)
{
  franka_control__srv__PandaSrv_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember franka_control__srv__PandaSrv_Response__rosidl_typesupport_introspection_c__PandaSrv_Response_message_member_array[1] = {
  {
    "flag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(franka_control__srv__PandaSrv_Response, flag),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers franka_control__srv__PandaSrv_Response__rosidl_typesupport_introspection_c__PandaSrv_Response_message_members = {
  "franka_control__srv",  // message namespace
  "PandaSrv_Response",  // message name
  1,  // number of fields
  sizeof(franka_control__srv__PandaSrv_Response),
  franka_control__srv__PandaSrv_Response__rosidl_typesupport_introspection_c__PandaSrv_Response_message_member_array,  // message members
  franka_control__srv__PandaSrv_Response__rosidl_typesupport_introspection_c__PandaSrv_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  franka_control__srv__PandaSrv_Response__rosidl_typesupport_introspection_c__PandaSrv_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t franka_control__srv__PandaSrv_Response__rosidl_typesupport_introspection_c__PandaSrv_Response_message_type_support_handle = {
  0,
  &franka_control__srv__PandaSrv_Response__rosidl_typesupport_introspection_c__PandaSrv_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_franka_control
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_control, srv, PandaSrv_Response)() {
  franka_control__srv__PandaSrv_Response__rosidl_typesupport_introspection_c__PandaSrv_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Float64)();
  if (!franka_control__srv__PandaSrv_Response__rosidl_typesupport_introspection_c__PandaSrv_Response_message_type_support_handle.typesupport_identifier) {
    franka_control__srv__PandaSrv_Response__rosidl_typesupport_introspection_c__PandaSrv_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &franka_control__srv__PandaSrv_Response__rosidl_typesupport_introspection_c__PandaSrv_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "franka_control/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "franka_control/srv/detail/panda_srv__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers franka_control__srv__detail__panda_srv__rosidl_typesupport_introspection_c__PandaSrv_service_members = {
  "franka_control__srv",  // service namespace
  "PandaSrv",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // franka_control__srv__detail__panda_srv__rosidl_typesupport_introspection_c__PandaSrv_Request_message_type_support_handle,
  NULL  // response message
  // franka_control__srv__detail__panda_srv__rosidl_typesupport_introspection_c__PandaSrv_Response_message_type_support_handle
};

static rosidl_service_type_support_t franka_control__srv__detail__panda_srv__rosidl_typesupport_introspection_c__PandaSrv_service_type_support_handle = {
  0,
  &franka_control__srv__detail__panda_srv__rosidl_typesupport_introspection_c__PandaSrv_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_control, srv, PandaSrv_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_control, srv, PandaSrv_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_franka_control
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_control, srv, PandaSrv)() {
  if (!franka_control__srv__detail__panda_srv__rosidl_typesupport_introspection_c__PandaSrv_service_type_support_handle.typesupport_identifier) {
    franka_control__srv__detail__panda_srv__rosidl_typesupport_introspection_c__PandaSrv_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)franka_control__srv__detail__panda_srv__rosidl_typesupport_introspection_c__PandaSrv_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_control, srv, PandaSrv_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_control, srv, PandaSrv_Response)()->data;
  }

  return &franka_control__srv__detail__panda_srv__rosidl_typesupport_introspection_c__PandaSrv_service_type_support_handle;
}
