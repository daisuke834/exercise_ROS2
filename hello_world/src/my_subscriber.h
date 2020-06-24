/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace my_subscriber {

class MySubscriber : public rclcpp::Node {
 public:
  MySubscriber(const std::string &node_name, const std::string &topic_name);

 private:
  void ReceiveMessage(const std_msgs::msg::String::SharedPtr msg) const;

 private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

}  // namespace my_subscriber
