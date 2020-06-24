/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */
#include "my_publisher.h"
#include <chrono>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace my_publisher {

constexpr size_t kQosHistoryDepth = 10U;

MyPublisher::MyPublisher(const std::string &node_name, const std::string &topic_name) : Node(node_name), count_(0) {
  publisher_ = this->create_publisher<std_msgs::msg::String>(topic_name, kQosHistoryDepth);
  const std::chrono::milliseconds kDuration(500);
  timer_ = this->create_wall_timer(kDuration, std::bind(&MyPublisher::PublishMessage, this));
}

void MyPublisher::PublishMessage() {
  std_msgs::msg::String message = std_msgs::msg::String();
  message.data = "Hello, world! " + std::to_string(count_);
  publisher_->publish(message);
  RCLCPP_INFO(this->get_logger(), "Published: '%s'", message.data.c_str());
  ++count_;
}

}  // namespace my_publisher
