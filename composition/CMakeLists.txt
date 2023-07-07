cmake_minimum_required(VERSION 3.5)
project(composition)

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

include_directories(include)

# ===========================
# Components
# create ament index resource which references the libraries in the binary dir
set(node_plugins "")
add_library(listener_component SHARED
  src/listener/listener_component.cpp
)
target_compile_definitions(listener_component
  PRIVATE "COMPOSITION_BUILDING_DLL"
)
ament_target_dependencies(listener_component
  "rclcpp"
  "rclcpp_components"
  "std_msgs"
)
rclcpp_components_register_nodes(listener_component "composition::Listener")
set(node_plugins "${node_plugins}composition::Listener;$<TARGET_FILE:listener_component>\n")

# ===========================
# Executable
add_executable(composition
  src/main.cpp
)
target_link_libraries(composition listener_component)
ament_target_dependencies(composition
    rclcpp
)
install(TARGETS
  composition
  DESTINATION lib/listener_component
)

ament_export_targets(export_listener_component HAS_LIBRARY_TARGET)
ament_export_include_directories(include)
ament_export_libraries(listener_component)

# install components
install(
  TARGETS listener_component
  EXPORT export_listener_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

# install headers
install(
      DIRECTORY include/
      DESTINATION include/
)

ament_package()