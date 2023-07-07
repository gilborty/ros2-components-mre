#include "composition/listener/listener_component.hpp"

namespace composition {
Listener::Listener(const rclcpp::NodeOptions & options)
    : Node("listener", options) {
  auto callback =
    [this](std_msgs::msg::String::ConstSharedPtr msg) -> void
    {
      RCLCPP_INFO(this->get_logger(), "I heard: [%s]", msg->data.c_str());
      std::flush(std::cout);
    };

  sub_ = create_subscription<std_msgs::msg::String>("chatter", 10, callback);
}
}  // namespace composition

#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(composition::Listener)