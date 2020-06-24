/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */
#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace my_publisher {

class MyPublisher : public rclcpp::Node {
 public:
  MyPublisher(const std::string &node_name, const std::string &topic_name);

 private:
  void PublishMessage();

 private:
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  int64_t count_;
};

}  // namespace my_publisher
