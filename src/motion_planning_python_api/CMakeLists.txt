cmake_minimum_required(VERSION 3.8)
project(motion_planning_python_api)

# Find dependencies
find_package(ament_cmake REQUIRED)

# Install the launch directory
install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

# Install the config directory
install(DIRECTORY config/
  DESTINATION share/${PROJECT_NAME}/config
)

ament_package()