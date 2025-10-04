// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from franka_control:srv/PandaSrv.idl
// generated code does not contain a copyright notice

#ifndef FRANKA_CONTROL__SRV__DETAIL__PANDA_SRV__STRUCT_HPP_
#define FRANKA_CONTROL__SRV__DETAIL__PANDA_SRV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'grasps'
#include "std_msgs/msg/detail/float64_multi_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__franka_control__srv__PandaSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__franka_control__srv__PandaSrv_Request __declspec(deprecated)
#endif

namespace franka_control
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PandaSrv_Request_
{
  using Type = PandaSrv_Request_<ContainerAllocator>;

  explicit PandaSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : grasps(_init)
  {
    (void)_init;
  }

  explicit PandaSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : grasps(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _grasps_type =
    std_msgs::msg::Float64MultiArray_<ContainerAllocator>;
  _grasps_type grasps;

  // setters for named parameter idiom
  Type & set__grasps(
    const std_msgs::msg::Float64MultiArray_<ContainerAllocator> & _arg)
  {
    this->grasps = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    franka_control::srv::PandaSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const franka_control::srv::PandaSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<franka_control::srv::PandaSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<franka_control::srv::PandaSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      franka_control::srv::PandaSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<franka_control::srv::PandaSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      franka_control::srv::PandaSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<franka_control::srv::PandaSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<franka_control::srv::PandaSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<franka_control::srv::PandaSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__franka_control__srv__PandaSrv_Request
    std::shared_ptr<franka_control::srv::PandaSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__franka_control__srv__PandaSrv_Request
    std::shared_ptr<franka_control::srv::PandaSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PandaSrv_Request_ & other) const
  {
    if (this->grasps != other.grasps) {
      return false;
    }
    return true;
  }
  bool operator!=(const PandaSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PandaSrv_Request_

// alias to use template instance with default allocator
using PandaSrv_Request =
  franka_control::srv::PandaSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace franka_control


// Include directives for member types
// Member 'flag'
#include "std_msgs/msg/detail/float64__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__franka_control__srv__PandaSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__franka_control__srv__PandaSrv_Response __declspec(deprecated)
#endif

namespace franka_control
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PandaSrv_Response_
{
  using Type = PandaSrv_Response_<ContainerAllocator>;

  explicit PandaSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : flag(_init)
  {
    (void)_init;
  }

  explicit PandaSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : flag(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _flag_type =
    std_msgs::msg::Float64_<ContainerAllocator>;
  _flag_type flag;

  // setters for named parameter idiom
  Type & set__flag(
    const std_msgs::msg::Float64_<ContainerAllocator> & _arg)
  {
    this->flag = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    franka_control::srv::PandaSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const franka_control::srv::PandaSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<franka_control::srv::PandaSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<franka_control::srv::PandaSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      franka_control::srv::PandaSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<franka_control::srv::PandaSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      franka_control::srv::PandaSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<franka_control::srv::PandaSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<franka_control::srv::PandaSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<franka_control::srv::PandaSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__franka_control__srv__PandaSrv_Response
    std::shared_ptr<franka_control::srv::PandaSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__franka_control__srv__PandaSrv_Response
    std::shared_ptr<franka_control::srv::PandaSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PandaSrv_Response_ & other) const
  {
    if (this->flag != other.flag) {
      return false;
    }
    return true;
  }
  bool operator!=(const PandaSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PandaSrv_Response_

// alias to use template instance with default allocator
using PandaSrv_Response =
  franka_control::srv::PandaSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace franka_control

namespace franka_control
{

namespace srv
{

struct PandaSrv
{
  using Request = franka_control::srv::PandaSrv_Request;
  using Response = franka_control::srv::PandaSrv_Response;
};

}  // namespace srv

}  // namespace franka_control

#endif  // FRANKA_CONTROL__SRV__DETAIL__PANDA_SRV__STRUCT_HPP_
