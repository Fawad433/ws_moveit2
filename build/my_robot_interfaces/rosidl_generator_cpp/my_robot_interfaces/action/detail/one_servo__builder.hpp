// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:action/OneServo.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__ACTION__DETAIL__ONE_SERVO__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__ACTION__DETAIL__ONE_SERVO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/action/detail/one_servo__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_OneServo_Goal_speeds
{
public:
  explicit Init_OneServo_Goal_speeds(::my_robot_interfaces::action::OneServo_Goal & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::OneServo_Goal speeds(::my_robot_interfaces::action::OneServo_Goal::_speeds_type arg)
  {
    msg_.speeds = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::OneServo_Goal msg_;
};

class Init_OneServo_Goal_angles
{
public:
  Init_OneServo_Goal_angles()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OneServo_Goal_speeds angles(::my_robot_interfaces::action::OneServo_Goal::_angles_type arg)
  {
    msg_.angles = std::move(arg);
    return Init_OneServo_Goal_speeds(msg_);
  }

private:
  ::my_robot_interfaces::action::OneServo_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::OneServo_Goal>()
{
  return my_robot_interfaces::action::builder::Init_OneServo_Goal_angles();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_OneServo_Result_reached_angles
{
public:
  Init_OneServo_Result_reached_angles()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::action::OneServo_Result reached_angles(::my_robot_interfaces::action::OneServo_Result::_reached_angles_type arg)
  {
    msg_.reached_angles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::OneServo_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::OneServo_Result>()
{
  return my_robot_interfaces::action::builder::Init_OneServo_Result_reached_angles();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_OneServo_Feedback_current_angles
{
public:
  Init_OneServo_Feedback_current_angles()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::action::OneServo_Feedback current_angles(::my_robot_interfaces::action::OneServo_Feedback::_current_angles_type arg)
  {
    msg_.current_angles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::OneServo_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::OneServo_Feedback>()
{
  return my_robot_interfaces::action::builder::Init_OneServo_Feedback_current_angles();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_OneServo_SendGoal_Request_goal
{
public:
  explicit Init_OneServo_SendGoal_Request_goal(::my_robot_interfaces::action::OneServo_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::OneServo_SendGoal_Request goal(::my_robot_interfaces::action::OneServo_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::OneServo_SendGoal_Request msg_;
};

class Init_OneServo_SendGoal_Request_goal_id
{
public:
  Init_OneServo_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OneServo_SendGoal_Request_goal goal_id(::my_robot_interfaces::action::OneServo_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_OneServo_SendGoal_Request_goal(msg_);
  }

private:
  ::my_robot_interfaces::action::OneServo_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::OneServo_SendGoal_Request>()
{
  return my_robot_interfaces::action::builder::Init_OneServo_SendGoal_Request_goal_id();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_OneServo_SendGoal_Response_stamp
{
public:
  explicit Init_OneServo_SendGoal_Response_stamp(::my_robot_interfaces::action::OneServo_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::OneServo_SendGoal_Response stamp(::my_robot_interfaces::action::OneServo_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::OneServo_SendGoal_Response msg_;
};

class Init_OneServo_SendGoal_Response_accepted
{
public:
  Init_OneServo_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OneServo_SendGoal_Response_stamp accepted(::my_robot_interfaces::action::OneServo_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_OneServo_SendGoal_Response_stamp(msg_);
  }

private:
  ::my_robot_interfaces::action::OneServo_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::OneServo_SendGoal_Response>()
{
  return my_robot_interfaces::action::builder::Init_OneServo_SendGoal_Response_accepted();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_OneServo_GetResult_Request_goal_id
{
public:
  Init_OneServo_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::action::OneServo_GetResult_Request goal_id(::my_robot_interfaces::action::OneServo_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::OneServo_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::OneServo_GetResult_Request>()
{
  return my_robot_interfaces::action::builder::Init_OneServo_GetResult_Request_goal_id();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_OneServo_GetResult_Response_result
{
public:
  explicit Init_OneServo_GetResult_Response_result(::my_robot_interfaces::action::OneServo_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::OneServo_GetResult_Response result(::my_robot_interfaces::action::OneServo_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::OneServo_GetResult_Response msg_;
};

class Init_OneServo_GetResult_Response_status
{
public:
  Init_OneServo_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OneServo_GetResult_Response_result status(::my_robot_interfaces::action::OneServo_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_OneServo_GetResult_Response_result(msg_);
  }

private:
  ::my_robot_interfaces::action::OneServo_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::OneServo_GetResult_Response>()
{
  return my_robot_interfaces::action::builder::Init_OneServo_GetResult_Response_status();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_OneServo_FeedbackMessage_feedback
{
public:
  explicit Init_OneServo_FeedbackMessage_feedback(::my_robot_interfaces::action::OneServo_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::OneServo_FeedbackMessage feedback(::my_robot_interfaces::action::OneServo_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::OneServo_FeedbackMessage msg_;
};

class Init_OneServo_FeedbackMessage_goal_id
{
public:
  Init_OneServo_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OneServo_FeedbackMessage_feedback goal_id(::my_robot_interfaces::action::OneServo_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_OneServo_FeedbackMessage_feedback(msg_);
  }

private:
  ::my_robot_interfaces::action::OneServo_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::OneServo_FeedbackMessage>()
{
  return my_robot_interfaces::action::builder::Init_OneServo_FeedbackMessage_goal_id();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__ACTION__DETAIL__ONE_SERVO__BUILDER_HPP_
