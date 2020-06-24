/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace my_subscriber {

constexpr size_t kQosHistoryDepth = 10U;

class MySubscriber : public rclcpp::Node {
 public:
  MySubscriber(const std::string &node_name, const std::string &topic_name) : Node(node_name) {
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        topic_name, kQosHistoryDepth, std::bind(&MySubscriber::ReceiveMessage, this, std::placeholders::_1));
  }

 private:
  void ReceiveMessage(const std_msgs::msg::String::SharedPtr msg) const {
    RCLCPP_INFO(this->get_logger(), "Received: '%s'", msg->data.c_str());
  }

 private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

}  // namespace my_subscriber

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<my_subscriber::MySubscriber>("my_subscriber", "topic"));
  rclcpp::shutdown();
  return 0;
}
