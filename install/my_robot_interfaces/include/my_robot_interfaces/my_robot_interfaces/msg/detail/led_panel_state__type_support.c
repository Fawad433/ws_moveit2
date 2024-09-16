// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from my_robot_interfaces:msg/LedPanelState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "my_robot_interfaces/msg/detail/led_panel_state__rosidl_typesupport_introspection_c.h"
#include "my_robot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "my_robot_interfaces/msg/detail/led_panel_state__functions.h"
#include "my_robot_interfaces/msg/detail/led_panel_state__struct.h"


// Include directives for member types
// Member `led_panel_state`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__LedPanelState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  my_robot_interfaces__msg__LedPanelState__init(message_memory);
}

void my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__LedPanelState_fini_function(void * message_memory)
{
  my_robot_interfaces__msg__LedPanelState__fini(message_memory);
}

size_t my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__size_function__LedPanelState__led_panel_state(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__get_const_function__LedPanelState__led_panel_state(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__get_function__LedPanelState__led_panel_state(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__fetch_function__LedPanelState__led_panel_state(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__get_const_function__LedPanelState__led_panel_state(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__assign_function__LedPanelState__led_panel_state(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__get_function__LedPanelState__led_panel_state(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__resize_function__LedPanelState__led_panel_state(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__LedPanelState_message_member_array[1] = {
  {
    "led_panel_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__msg__LedPanelState, led_panel_state),  // bytes offset in struct
    NULL,  // default value
    my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__size_function__LedPanelState__led_panel_state,  // size() function pointer
    my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__get_const_function__LedPanelState__led_panel_state,  // get_const(index) function pointer
    my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__get_function__LedPanelState__led_panel_state,  // get(index) function pointer
    my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__fetch_function__LedPanelState__led_panel_state,  // fetch(index, &value) function pointer
    my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__assign_function__LedPanelState__led_panel_state,  // assign(index, value) function pointer
    my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__resize_function__LedPanelState__led_panel_state  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__LedPanelState_message_members = {
  "my_robot_interfaces__msg",  // message namespace
  "LedPanelState",  // message name
  1,  // number of fields
  sizeof(my_robot_interfaces__msg__LedPanelState),
  my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__LedPanelState_message_member_array,  // message members
  my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__LedPanelState_init_function,  // function to initialize message memory (memory has to be allocated)
  my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__LedPanelState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__LedPanelState_message_type_support_handle = {
  0,
  &my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__LedPanelState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_robot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, msg, LedPanelState)() {
  if (!my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__LedPanelState_message_type_support_handle.typesupport_identifier) {
    my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__LedPanelState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &my_robot_interfaces__msg__LedPanelState__rosidl_typesupport_introspection_c__LedPanelState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
