#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from sensor_msgs.msg import JointState  # To subscribe to joint states
from rclpy.action.client import ClientGoalHandle
from my_robot_interfaces.action import OneServo
import math


class ServoClientClientNode(Node):
    def __init__(self):
        super().__init__("servo_client_client")  # Node name

        # Declare parameters with default values for angles and speeds
        self.declare_parameter("angles", [90.0, 0.0, 0.0, 0.0, 0.0, 0.0])
        self.declare_parameter("speeds", [5.0, 5.0, 5.0, 5.0, 5.0, 5.0])

        # Retrieve the parameter values
        self.angles = self.get_parameter("angles").value
        self.speeds = self.get_parameter("speeds").value

        # Ensure angles and speeds are lists of floats
        self.angles = list(map(float, self.angles))
        self.speeds = list(map(float, self.speeds))

        # Define the action client
        self.servo_client__client = ActionClient(self, OneServo, "one_servo")

        # Add a subscriber for joint states (MoveIt2 or any publisher providing joint positions)
        self.joint_state_subscriber = self.create_subscription(
            JointState,
            '/joint_states',  # Replace this with your custom topic if necessary
            self.joint_state_callback,
            10  # Queue size
        )

        self.get_logger().info("ServoClientClientNode initialized with joint state subscriber.")

    def send_goal(self):
        self.servo_client__client.wait_for_server()

        # Create a goal
        goal = OneServo.Goal()
        goal.angles = self.angles  # Set angles
        goal.speeds = self.speeds  # Set speeds

        # Log the goal for debugging
        self.get_logger().info(f"Sending goal with angles: {self.angles} and speeds: {self.speeds}")

        # Send the goal
        self.servo_client__client.\
            send_goal_async(goal).\
            add_done_callback(self.goal_response_callback)

    def joint_state_callback(self, msg: JointState):
        """
        Callback function that processes the received joint state.
        Converts positions to servo angles and sends the goal.
        """
        self.get_logger().info(f"Received joint state: {msg.position}")

        # Convert the joint positions (in radians) to servo angles (in degrees)
        self.angles = [self.convert_position_to_angle(pos) for pos in msg.position[:6]]  # Assume first 6 positions

        # Log the converted angles for debugging
        self.get_logger().info(f"Converted angles: {self.angles}")

        # Send the goal with the new angles
        self.send_goal()

    def convert_position_to_angle(self, position):
        """
        Converts a joint position in radians to a servo angle in degrees.
        Assumes the servo angle range is 0 to 180 degrees, and the joint range
        is -π to +π radians (modify based on your robot configuration).
        """
        # Assuming the joint moves between -π to +π radians (or adjust based on joint limits)
        #servo_min_angle = 0.0   # Minimum servo angle in degrees
        #servo_max_angle = 180.0 # Maximum servo angle in degrees

        #joint_min_position = -math.pi  # Min joint position in radians
        #joint_max_position = math.pi   # Max joint position in radians

        # Convert radians to degrees and map to the servo's range
        # This maps position from [-π, +π] to [0, 180] degrees
        #angle = (position - joint_min_position) * (servo_max_angle - servo_min_angle) / (joint_max_position - joint_min_position) + servo_min_angle

        # Ensure the angle is within servo limits
        #angle = max(servo_min_angle, min(servo_max_angle, angle))
        angle = position * 57.2958
        self.get_logger().info(f"Converted angle: {angle}")
        return angle

    def goal_response_callback(self, future):
        self.goal_handle_: ClientGoalHandle = future.result()
        if self.goal_handle_.accepted:
            self.get_logger().info("Goal accepted")
            self.goal_handle_.get_result_async().add_done_callback(self.goal_result_callback)
        else:
            self.get_logger().info("Goal rejected")

    def goal_result_callback(self, future):
        result = future.result().result
        self.get_logger().info("Result: " + str(result.reached_angles))


def main(args=None):
    rclpy.init(args=args)
    node = ServoClientClientNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
