# CMake generated Testfile for 
# Source directory: /home/robot/ws_moveit2/src/moveit2/moveit_ros/move_group
# Build directory: /home/robot/ws_moveit2/build/moveit_ros_move_group
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[cppcheck]=] "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/robot/ws_moveit2/build/moveit_ros_move_group/test_results/moveit_ros_move_group/cppcheck.xunit.xml" "--package-name" "moveit_ros_move_group" "--output-file" "/home/robot/ws_moveit2/build/moveit_ros_move_group/ament_cppcheck/cppcheck.txt" "--command" "/opt/ros/humble/bin/ament_cppcheck" "--xunit-file" "/home/robot/ws_moveit2/build/moveit_ros_move_group/test_results/moveit_ros_move_group/cppcheck.xunit.xml" "--include_dirs" "/home/robot/ws_moveit2/src/moveit2/moveit_ros/move_group/include")
set_tests_properties([=[cppcheck]=] PROPERTIES  LABELS "cppcheck;linter" TIMEOUT "300" WORKING_DIRECTORY "/home/robot/ws_moveit2/src/moveit2/moveit_ros/move_group" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_cppcheck/cmake/ament_cppcheck.cmake;66;ament_add_test;/opt/ros/humble/share/ament_cmake_cppcheck/cmake/ament_cmake_cppcheck_lint_hook.cmake;87;ament_cppcheck;/opt/ros/humble/share/ament_cmake_cppcheck/cmake/ament_cmake_cppcheck_lint_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/robot/ws_moveit2/src/moveit2/moveit_ros/move_group/CMakeLists.txt;128;ament_package;/home/robot/ws_moveit2/src/moveit2/moveit_ros/move_group/CMakeLists.txt;0;")
add_test([=[lint_cmake]=] "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/robot/ws_moveit2/build/moveit_ros_move_group/test_results/moveit_ros_move_group/lint_cmake.xunit.xml" "--package-name" "moveit_ros_move_group" "--output-file" "/home/robot/ws_moveit2/build/moveit_ros_move_group/ament_lint_cmake/lint_cmake.txt" "--command" "/opt/ros/humble/bin/ament_lint_cmake" "--xunit-file" "/home/robot/ws_moveit2/build/moveit_ros_move_group/test_results/moveit_ros_move_group/lint_cmake.xunit.xml")
set_tests_properties([=[lint_cmake]=] PROPERTIES  LABELS "lint_cmake;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/robot/ws_moveit2/src/moveit2/moveit_ros/move_group" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_lint_cmake/cmake/ament_lint_cmake.cmake;47;ament_add_test;/opt/ros/humble/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;21;ament_lint_cmake;/opt/ros/humble/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/robot/ws_moveit2/src/moveit2/moveit_ros/move_group/CMakeLists.txt;128;ament_package;/home/robot/ws_moveit2/src/moveit2/moveit_ros/move_group/CMakeLists.txt;0;")
add_test([=[pep257]=] "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/robot/ws_moveit2/build/moveit_ros_move_group/test_results/moveit_ros_move_group/pep257.xunit.xml" "--package-name" "moveit_ros_move_group" "--output-file" "/home/robot/ws_moveit2/build/moveit_ros_move_group/ament_pep257/pep257.txt" "--command" "/opt/ros/humble/bin/ament_pep257" "--xunit-file" "/home/robot/ws_moveit2/build/moveit_ros_move_group/test_results/moveit_ros_move_group/pep257.xunit.xml")
set_tests_properties([=[pep257]=] PROPERTIES  LABELS "pep257;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/robot/ws_moveit2/src/moveit2/moveit_ros/move_group" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_pep257/cmake/ament_pep257.cmake;41;ament_add_test;/opt/ros/humble/share/ament_cmake_pep257/cmake/ament_cmake_pep257_lint_hook.cmake;18;ament_pep257;/opt/ros/humble/share/ament_cmake_pep257/cmake/ament_cmake_pep257_lint_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/robot/ws_moveit2/src/moveit2/moveit_ros/move_group/CMakeLists.txt;128;ament_package;/home/robot/ws_moveit2/src/moveit2/moveit_ros/move_group/CMakeLists.txt;0;")
add_test([=[xmllint]=] "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/robot/ws_moveit2/build/moveit_ros_move_group/test_results/moveit_ros_move_group/xmllint.xunit.xml" "--package-name" "moveit_ros_move_group" "--output-file" "/home/robot/ws_moveit2/build/moveit_ros_move_group/ament_xmllint/xmllint.txt" "--command" "/opt/ros/humble/bin/ament_xmllint" "--xunit-file" "/home/robot/ws_moveit2/build/moveit_ros_move_group/test_results/moveit_ros_move_group/xmllint.xunit.xml")
set_tests_properties([=[xmllint]=] PROPERTIES  LABELS "xmllint;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/robot/ws_moveit2/src/moveit2/moveit_ros/move_group" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_xmllint/cmake/ament_xmllint.cmake;50;ament_add_test;/opt/ros/humble/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;18;ament_xmllint;/opt/ros/humble/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/robot/ws_moveit2/src/moveit2/moveit_ros/move_group/CMakeLists.txt;128;ament_package;/home/robot/ws_moveit2/src/moveit2/moveit_ros/move_group/CMakeLists.txt;0;")
