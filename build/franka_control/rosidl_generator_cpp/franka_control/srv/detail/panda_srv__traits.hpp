// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from franka_control:srv/PandaSrv.idl
// generated code does not contain a copyright notice

#ifndef FRANKA_CONTROL__SRV__DETAIL__PANDA_SRV__TRAITS_HPP_
#define FRANKA_CONTROL__SRV__DETAIL__PANDA_SRV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "franka_control/srv/detail/panda_srv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'grasps'
#include "std_msgs/msg/detail/float64_multi_array__traits.hpp"

namespace franka_control
{

namespace srv
{

inline void to_flow_style_yaml(
  const PandaSrv_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: grasps
  {
    out << "grasps: ";
    to_flow_style_yaml(msg.grasps, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PandaSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: grasps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "grasps:\n";
    to_block_style_yaml(msg.grasps, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PandaSrv_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace franka_control

namespace rosidl_generator_traits
{

[[deprecated("use franka_control::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const franka_control::srv::PandaSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  franka_control::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use franka_control::srv::to_yaml() instead")]]
inline std::string to_yaml(const franka_control::srv::PandaSrv_Request & msg)
{
  return franka_control::srv::to_yaml(msg);
}

template<>
inline const char * data_type<franka_control::srv::PandaSrv_Request>()
{
  return "franka_control::srv::PandaSrv_Request";
}

template<>
inline const char * name<franka_control::srv::PandaSrv_Request>()
{
  return "franka_control/srv/PandaSrv_Request";
}

template<>
struct has_fixed_size<franka_control::srv::PandaSrv_Request>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Float64MultiArray>::value> {};

template<>
struct has_bounded_size<franka_control::srv::PandaSrv_Request>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Float64MultiArray>::value> {};

template<>
struct is_message<franka_control::srv::PandaSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'flag'
#include "std_msgs/msg/detail/float64__traits.hpp"

namespace franka_control
{

namespace srv
{

inline void to_flow_style_yaml(
  const PandaSrv_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: flag
  {
    out << "flag: ";
    to_flow_style_yaml(msg.flag, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PandaSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: flag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flag:\n";
    to_block_style_yaml(msg.flag, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PandaSrv_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace franka_control

namespace rosidl_generator_traits
{

[[deprecated("use franka_control::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const franka_control::srv::PandaSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  franka_control::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use franka_control::srv::to_yaml() instead")]]
inline std::string to_yaml(const franka_control::srv::PandaSrv_Response & msg)
{
  return franka_control::srv::to_yaml(msg);
}

template<>
inline const char * data_type<franka_control::srv::PandaSrv_Response>()
{
  return "franka_control::srv::PandaSrv_Response";
}

template<>
inline const char * name<franka_control::srv::PandaSrv_Response>()
{
  return "franka_control/srv/PandaSrv_Response";
}

template<>
struct has_fixed_size<franka_control::srv::PandaSrv_Response>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Float64>::value> {};

template<>
struct has_bounded_size<franka_control::srv::PandaSrv_Response>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Float64>::value> {};

template<>
struct is_message<franka_control::srv::PandaSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<franka_control::srv::PandaSrv>()
{
  return "franka_control::srv::PandaSrv";
}

template<>
inline const char * name<franka_control::srv::PandaSrv>()
{
  return "franka_control/srv/PandaSrv";
}

template<>
struct has_fixed_size<franka_control::srv::PandaSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<franka_control::srv::PandaSrv_Request>::value &&
    has_fixed_size<franka_control::srv::PandaSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<franka_control::srv::PandaSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<franka_control::srv::PandaSrv_Request>::value &&
    has_bounded_size<franka_control::srv::PandaSrv_Response>::value
  >
{
};

template<>
struct is_service<franka_control::srv::PandaSrv>
  : std::true_type
{
};

template<>
struct is_service_request<franka_control::srv::PandaSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<franka_control::srv::PandaSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // FRANKA_CONTROL__SRV__DETAIL__PANDA_SRV__TRAITS_HPP_
