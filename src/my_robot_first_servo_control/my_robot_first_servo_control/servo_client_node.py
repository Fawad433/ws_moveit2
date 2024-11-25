#!/usr/bin/env python3
import rclpy
import requests
from rclpy.node import Node
from rclpy.action import ActionServer, GoalResponse
from rclpy.action.server import ServerGoalHandle
from my_robot_interfaces.action import OneServo


class ServoClientServerNode(Node):
    def __init__(self):
        super().__init__("servo_client_server")  # Node name
        self.count_until_server_ = ActionServer(
            self,
            OneServo,
            "one_servo",
            goal_callback=self.goal_callback,
            execute_callback=self.execute_callback
        )
        self.get_logger().info("Servo Client Action server started")

    def goal_callback(self, goal_request: OneServo.Goal):
        self.get_logger().info("Received a goal")
        if len(goal_request.angles) != len(goal_request.speeds):
            self.get_logger().info("Rejecting the goal: Mismatch between angles and speeds")
            return GoalResponse.REJECT
        else:
            self.get_logger().info("Accepting the goal")
            return GoalResponse.ACCEPT

    def execute_callback(self, goal_handle: ServerGoalHandle):
        angles = goal_handle.request.angles
        speeds = goal_handle.request.speeds

        self.get_logger().info("Executing the goal")
        ip = "10.0.0.150"
	# 2 3 1 4 5
        # Construct the query string in the required format
        #query_string = "&".join([f"angle{i}={angles[i]}&speed{i}={speeds[i]}" for i in range(len(angles))])
        if angles[5] > 0:
            angles[5] = 0
        if angles[5] == 0:
            angles[5] = 90
        url = f"http://10.0.0.150/?angle0={angles[2]}&speed0={speeds[2]}&angle1={angles[0]}&speed1={speeds[0]}&angle2={angles[1]}&speed2={speeds[1]}&angle3={angles[3]}&speed3={speeds[3]}&angle4={angles[4]}&speed4={speeds[4]}&angle5={angles[5]}&speed5={speeds[5]}"

        result = OneServo.Result()

        try:
            response = requests.get(url)
            if response.status_code == 200:
                self.get_logger().info("Request successful.")
                self.get_logger().info("Response from server: " + response.text)
                goal_handle.succeed()
                result.reached_angles = True
                return result
            else:
                self.get_logger().info(f"Failed to send request. Status code: {response.status_code}")
        except requests.exceptions.RequestException as e:
            self.get_logger().info(f"Error sending request: {e}")

        goal_handle.abort()
        result.reached_angles = False
        return result


def main(args=None):
    rclpy.init(args=args)
    node = ServoClientServerNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
