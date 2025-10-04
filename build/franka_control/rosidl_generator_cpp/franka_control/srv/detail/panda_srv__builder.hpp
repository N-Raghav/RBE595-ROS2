// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from franka_control:srv/PandaSrv.idl
// generated code does not contain a copyright notice

#ifndef FRANKA_CONTROL__SRV__DETAIL__PANDA_SRV__BUILDER_HPP_
#define FRANKA_CONTROL__SRV__DETAIL__PANDA_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "franka_control/srv/detail/panda_srv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace franka_control
{

namespace srv
{

namespace builder
{

class Init_PandaSrv_Request_grasps
{
public:
  Init_PandaSrv_Request_grasps()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::franka_control::srv::PandaSrv_Request grasps(::franka_control::srv::PandaSrv_Request::_grasps_type arg)
  {
    msg_.grasps = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_control::srv::PandaSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_control::srv::PandaSrv_Request>()
{
  return franka_control::srv::builder::Init_PandaSrv_Request_grasps();
}

}  // namespace franka_control


namespace franka_control
{

namespace srv
{

namespace builder
{

class Init_PandaSrv_Response_flag
{
public:
  Init_PandaSrv_Response_flag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::franka_control::srv::PandaSrv_Response flag(::franka_control::srv::PandaSrv_Response::_flag_type arg)
  {
    msg_.flag = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_control::srv::PandaSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_control::srv::PandaSrv_Response>()
{
  return franka_control::srv::builder::Init_PandaSrv_Response_flag();
}

}  // namespace franka_control

#endif  // FRANKA_CONTROL__SRV__DETAIL__PANDA_SRV__BUILDER_HPP_
