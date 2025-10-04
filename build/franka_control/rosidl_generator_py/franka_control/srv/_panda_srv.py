# generated from rosidl_generator_py/resource/_idl.py.em
# with input from franka_control:srv/PandaSrv.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PandaSrv_Request(type):
    """Metaclass of message 'PandaSrv_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('franka_control')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'franka_control.srv.PandaSrv_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__panda_srv__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__panda_srv__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__panda_srv__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__panda_srv__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__panda_srv__request

            from std_msgs.msg import Float64MultiArray
            if Float64MultiArray.__class__._TYPE_SUPPORT is None:
                Float64MultiArray.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PandaSrv_Request(metaclass=Metaclass_PandaSrv_Request):
    """Message class 'PandaSrv_Request'."""

    __slots__ = [
        '_grasps',
    ]

    _fields_and_field_types = {
        'grasps': 'std_msgs/Float64MultiArray',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Float64MultiArray'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Float64MultiArray
        self.grasps = kwargs.get('grasps', Float64MultiArray())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.grasps != other.grasps:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def grasps(self):
        """Message field 'grasps'."""
        return self._grasps

    @grasps.setter
    def grasps(self, value):
        if __debug__:
            from std_msgs.msg import Float64MultiArray
            assert \
                isinstance(value, Float64MultiArray), \
                "The 'grasps' field must be a sub message of type 'Float64MultiArray'"
        self._grasps = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_PandaSrv_Response(type):
    """Metaclass of message 'PandaSrv_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('franka_control')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'franka_control.srv.PandaSrv_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__panda_srv__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__panda_srv__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__panda_srv__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__panda_srv__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__panda_srv__response

            from std_msgs.msg import Float64
            if Float64.__class__._TYPE_SUPPORT is None:
                Float64.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PandaSrv_Response(metaclass=Metaclass_PandaSrv_Response):
    """Message class 'PandaSrv_Response'."""

    __slots__ = [
        '_flag',
    ]

    _fields_and_field_types = {
        'flag': 'std_msgs/Float64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Float64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Float64
        self.flag = kwargs.get('flag', Float64())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.flag != other.flag:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def flag(self):
        """Message field 'flag'."""
        return self._flag

    @flag.setter
    def flag(self, value):
        if __debug__:
            from std_msgs.msg import Float64
            assert \
                isinstance(value, Float64), \
                "The 'flag' field must be a sub message of type 'Float64'"
        self._flag = value


class Metaclass_PandaSrv(type):
    """Metaclass of service 'PandaSrv'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('franka_control')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'franka_control.srv.PandaSrv')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__panda_srv

            from franka_control.srv import _panda_srv
            if _panda_srv.Metaclass_PandaSrv_Request._TYPE_SUPPORT is None:
                _panda_srv.Metaclass_PandaSrv_Request.__import_type_support__()
            if _panda_srv.Metaclass_PandaSrv_Response._TYPE_SUPPORT is None:
                _panda_srv.Metaclass_PandaSrv_Response.__import_type_support__()


class PandaSrv(metaclass=Metaclass_PandaSrv):
    from franka_control.srv._panda_srv import PandaSrv_Request as Request
    from franka_control.srv._panda_srv import PandaSrv_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
