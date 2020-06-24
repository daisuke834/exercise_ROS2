/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */
#include <rclcpp/rclcpp.hpp>
#include "my_publisher.h"
#include "my_subscriber.h"

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::executors::MultiThreadedExecutor exec;

  auto node1 = std::make_shared<my_publisher::MyPublisher>("my_publisher", "topic");
  exec.add_node(node1);
  auto node2 = std::make_shared<my_subscriber::MySubscriber>("my_subscriber", "topic");
  exec.add_node(node2);
  exec.spin();

  rclcpp::shutdown();
  return 0;
}
