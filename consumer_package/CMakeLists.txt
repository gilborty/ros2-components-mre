cmake_minimum_required(VERSION 3.5)
project(consumer_package)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Wno-unknown-pragmas)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)
find_package(composition REQUIRED)

# ===========================
# Executable
add_executable(consumer_package
  src/main.cpp
)
target_link_libraries(consumer_package listener_component)
ament_target_dependencies(consumer_package
    rclcpp
    composition
)
install(TARGETS
consumer_package
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()