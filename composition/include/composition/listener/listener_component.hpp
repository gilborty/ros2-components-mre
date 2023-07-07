#pragma once

#include "composition/visibility_control.hpp"

#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/string.hpp"


namespace composition {
class Listener : public rclcpp::Node {
public:
  explicit Listener(const rclcpp::NodeOptions& options);

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
}; 

}  // namespace composition