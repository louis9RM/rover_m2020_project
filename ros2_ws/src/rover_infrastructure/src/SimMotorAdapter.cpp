#include "rover_infrastructure/SimMotorAdapter.hpp"

namespace rover_infrastructure {

SimMotorAdapter::SimMotorAdapter(rclcpp::Node::SharedPtr node) : node_(node) {
  // Usually publisher needs QoS
  pub_ = node_->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
}

void SimMotorAdapter::set_velocity(double linear_x, double angular_z) {
  geometry_msgs::msg::Twist msg;
  msg.linear.x = linear_x;
  msg.angular.z = angular_z;
  pub_->publish(msg);
}

void SimMotorAdapter::stop() { set_velocity(0.0, 0.0); }

} // namespace rover_infrastructure
