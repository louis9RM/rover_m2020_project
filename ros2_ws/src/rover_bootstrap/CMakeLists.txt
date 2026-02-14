cmake_minimum_required(VERSION 3.8)
project(rover_bootstrap)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rover_core REQUIRED)
find_package(rover_infrastructure REQUIRED)
find_package(rover_ports REQUIRED)

add_executable(rover_bootstrap_node src/main.cpp)
target_include_directories(rover_bootstrap_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(rover_bootstrap_node
  rclcpp
  rover_core
  rover_infrastructure
  rover_ports
)

install(TARGETS rover_bootstrap_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
