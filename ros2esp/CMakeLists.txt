cmake_minimum_required(VERSION 3.8)
project(ros2esp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)


add_executable(mros_wip src/mROS_WIP.cpp)
ament_target_dependencies(mros_wip rclcpp std_msgs sensor_msgs)

add_executable(mb_tester src/MB_TESTER.cpp)
ament_target_dependencies(mb_tester rclcpp std_msgs sensor_msgs)

add_executable(esp src/esp.cpp)
ament_target_dependencies(esp rclcpp std_msgs sensor_msgs)

add_executable(nr25_mrs src/NR25_MR_SwerveDrive.cpp)
ament_target_dependencies(nr25_mr rclcpp std_msgs sensor_msgs)

add_executable(ps4listener src/ps4listener.cpp)
ament_target_dependencies(ps4listener rclcpp std_msgs sensor_msgs)


# インストール設定
install(TARGETS
  mros_wip
  mb_tester
  esp
  nr25_mr
  ps4listener
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
