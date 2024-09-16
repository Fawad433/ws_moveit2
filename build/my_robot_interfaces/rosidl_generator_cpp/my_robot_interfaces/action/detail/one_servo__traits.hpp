// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_robot_interfaces:action/OneServo.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__ACTION__DETAIL__ONE_SERVO__TRAITS_HPP_
#define MY_ROBOT_INTERFACES__ACTION__DETAIL__ONE_SERVO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_robot_interfaces/action/detail/one_servo__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_robot_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const OneServo_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: angles
  {
    if (msg.angles.size() == 0) {
      out << "angles: []";
    } else {
      out << "angles: [";
      size_t pending_items = msg.angles.size();
      for (auto item : msg.angles) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: speeds
  {
    if (msg.speeds.size() == 0) {
      out << "speeds: []";
    } else {
      out << "speeds: [";
      size_t pending_items = msg.speeds.size();
      for (auto item : msg.speeds) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OneServo_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: angles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.angles.size() == 0) {
      out << "angles: []\n";
    } else {
      out << "angles:\n";
      for (auto item : msg.angles) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: speeds
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.speeds.size() == 0) {
      out << "speeds: []\n";
    } else {
      out << "speeds:\n";
      for (auto item : msg.speeds) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OneServo_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::action::OneServo_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::action::OneServo_Goal & msg)
{
  return my_robot_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::action::OneServo_Goal>()
{
  return "my_robot_interfaces::action::OneServo_Goal";
}

template<>
inline const char * name<my_robot_interfaces::action::OneServo_Goal>()
{
  return "my_robot_interfaces/action/OneServo_Goal";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::OneServo_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_robot_interfaces::action::OneServo_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_robot_interfaces::action::OneServo_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace my_robot_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const OneServo_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: reached_angles
  {
    out << "reached_angles: ";
    rosidl_generator_traits::value_to_yaml(msg.reached_angles, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OneServo_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: reached_angles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reached_angles: ";
    rosidl_generator_traits::value_to_yaml(msg.reached_angles, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OneServo_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::action::OneServo_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::action::OneServo_Result & msg)
{
  return my_robot_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::action::OneServo_Result>()
{
  return "my_robot_interfaces::action::OneServo_Result";
}

template<>
inline const char * name<my_robot_interfaces::action::OneServo_Result>()
{
  return "my_robot_interfaces/action/OneServo_Result";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::OneServo_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_robot_interfaces::action::OneServo_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_robot_interfaces::action::OneServo_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace my_robot_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const OneServo_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_angles
  {
    if (msg.current_angles.size() == 0) {
      out << "current_angles: []";
    } else {
      out << "current_angles: [";
      size_t pending_items = msg.current_angles.size();
      for (auto item : msg.current_angles) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OneServo_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_angles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.current_angles.size() == 0) {
      out << "current_angles: []\n";
    } else {
      out << "current_angles:\n";
      for (auto item : msg.current_angles) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OneServo_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::action::OneServo_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::action::OneServo_Feedback & msg)
{
  return my_robot_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::action::OneServo_Feedback>()
{
  return "my_robot_interfaces::action::OneServo_Feedback";
}

template<>
inline const char * name<my_robot_interfaces::action::OneServo_Feedback>()
{
  return "my_robot_interfaces/action/OneServo_Feedback";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::OneServo_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_robot_interfaces::action::OneServo_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_robot_interfaces::action::OneServo_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "my_robot_interfaces/action/detail/one_servo__traits.hpp"

namespace my_robot_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const OneServo_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OneServo_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OneServo_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::action::OneServo_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::action::OneServo_SendGoal_Request & msg)
{
  return my_robot_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::action::OneServo_SendGoal_Request>()
{
  return "my_robot_interfaces::action::OneServo_SendGoal_Request";
}

template<>
inline const char * name<my_robot_interfaces::action::OneServo_SendGoal_Request>()
{
  return "my_robot_interfaces/action/OneServo_SendGoal_Request";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::OneServo_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<my_robot_interfaces::action::OneServo_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<my_robot_interfaces::action::OneServo_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<my_robot_interfaces::action::OneServo_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<my_robot_interfaces::action::OneServo_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace my_robot_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const OneServo_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OneServo_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OneServo_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::action::OneServo_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::action::OneServo_SendGoal_Response & msg)
{
  return my_robot_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::action::OneServo_SendGoal_Response>()
{
  return "my_robot_interfaces::action::OneServo_SendGoal_Response";
}

template<>
inline const char * name<my_robot_interfaces::action::OneServo_SendGoal_Response>()
{
  return "my_robot_interfaces/action/OneServo_SendGoal_Response";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::OneServo_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<my_robot_interfaces::action::OneServo_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<my_robot_interfaces::action::OneServo_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<my_robot_interfaces::action::OneServo_SendGoal>()
{
  return "my_robot_interfaces::action::OneServo_SendGoal";
}

template<>
inline const char * name<my_robot_interfaces::action::OneServo_SendGoal>()
{
  return "my_robot_interfaces/action/OneServo_SendGoal";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::OneServo_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<my_robot_interfaces::action::OneServo_SendGoal_Request>::value &&
    has_fixed_size<my_robot_interfaces::action::OneServo_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<my_robot_interfaces::action::OneServo_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<my_robot_interfaces::action::OneServo_SendGoal_Request>::value &&
    has_bounded_size<my_robot_interfaces::action::OneServo_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<my_robot_interfaces::action::OneServo_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<my_robot_interfaces::action::OneServo_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<my_robot_interfaces::action::OneServo_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace my_robot_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const OneServo_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OneServo_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OneServo_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::action::OneServo_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::action::OneServo_GetResult_Request & msg)
{
  return my_robot_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::action::OneServo_GetResult_Request>()
{
  return "my_robot_interfaces::action::OneServo_GetResult_Request";
}

template<>
inline const char * name<my_robot_interfaces::action::OneServo_GetResult_Request>()
{
  return "my_robot_interfaces/action/OneServo_GetResult_Request";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::OneServo_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<my_robot_interfaces::action::OneServo_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<my_robot_interfaces::action::OneServo_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "my_robot_interfaces/action/detail/one_servo__traits.hpp"

namespace my_robot_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const OneServo_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OneServo_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OneServo_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::action::OneServo_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::action::OneServo_GetResult_Response & msg)
{
  return my_robot_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::action::OneServo_GetResult_Response>()
{
  return "my_robot_interfaces::action::OneServo_GetResult_Response";
}

template<>
inline const char * name<my_robot_interfaces::action::OneServo_GetResult_Response>()
{
  return "my_robot_interfaces/action/OneServo_GetResult_Response";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::OneServo_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<my_robot_interfaces::action::OneServo_Result>::value> {};

template<>
struct has_bounded_size<my_robot_interfaces::action::OneServo_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<my_robot_interfaces::action::OneServo_Result>::value> {};

template<>
struct is_message<my_robot_interfaces::action::OneServo_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<my_robot_interfaces::action::OneServo_GetResult>()
{
  return "my_robot_interfaces::action::OneServo_GetResult";
}

template<>
inline const char * name<my_robot_interfaces::action::OneServo_GetResult>()
{
  return "my_robot_interfaces/action/OneServo_GetResult";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::OneServo_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<my_robot_interfaces::action::OneServo_GetResult_Request>::value &&
    has_fixed_size<my_robot_interfaces::action::OneServo_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<my_robot_interfaces::action::OneServo_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<my_robot_interfaces::action::OneServo_GetResult_Request>::value &&
    has_bounded_size<my_robot_interfaces::action::OneServo_GetResult_Response>::value
  >
{
};

template<>
struct is_service<my_robot_interfaces::action::OneServo_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<my_robot_interfaces::action::OneServo_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<my_robot_interfaces::action::OneServo_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "my_robot_interfaces/action/detail/one_servo__traits.hpp"

namespace my_robot_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const OneServo_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OneServo_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OneServo_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::action::OneServo_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::action::OneServo_FeedbackMessage & msg)
{
  return my_robot_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::action::OneServo_FeedbackMessage>()
{
  return "my_robot_interfaces::action::OneServo_FeedbackMessage";
}

template<>
inline const char * name<my_robot_interfaces::action::OneServo_FeedbackMessage>()
{
  return "my_robot_interfaces/action/OneServo_FeedbackMessage";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::OneServo_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<my_robot_interfaces::action::OneServo_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<my_robot_interfaces::action::OneServo_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<my_robot_interfaces::action::OneServo_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<my_robot_interfaces::action::OneServo_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<my_robot_interfaces::action::OneServo>
  : std::true_type
{
};

template<>
struct is_action_goal<my_robot_interfaces::action::OneServo_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<my_robot_interfaces::action::OneServo_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<my_robot_interfaces::action::OneServo_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // MY_ROBOT_INTERFACES__ACTION__DETAIL__ONE_SERVO__TRAITS_HPP_
