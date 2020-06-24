/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */
#include "my_subscriber.h"
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace my_subscriber {

constexpr size_t kQosHistoryDepth = 10U;

MySubscriber::MySubscriber(const std::string &node_name, const std::string &topic_name) : Node(node_name) {
  subscription_ = this->create_subscription<std_msgs::msg::String>(
      topic_name, kQosHistoryDepth, std::bind(&MySubscriber::ReceiveMessage, this, std::placeholders::_1));
}

void MySubscriber::ReceiveMessage(const std_msgs::msg::String::SharedPtr msg) const {
  RCLCPP_INFO(this->get_logger(), "Received: '%s'", msg->data.c_str());
}

}  // namespace my_subscriber
