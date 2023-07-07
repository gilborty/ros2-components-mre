#include <iostream>

#include "composition/listener/listener_component.hpp"

int main(const int argc, const char* argv[]) {
    // Force flush of the stdout buffer.
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);

    rclcpp::init(argc, argv);
    rclcpp::executors::SingleThreadedExecutor exec;
    rclcpp::NodeOptions options;

    auto listener_component = std::make_shared<composition::Listener>(options);
    exec.add_node(listener_component);
    exec.spin();
    rclcpp::shutdown();
}
