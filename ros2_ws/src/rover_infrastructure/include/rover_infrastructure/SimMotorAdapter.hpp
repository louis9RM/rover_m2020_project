#pragma once
#include "rover_ports/IMotorControls.hpp"
#include <geometry_msgs/msg/twist.hpp>
#include <rclcpp/rclcpp.hpp>

namespace rover_infrastructure {

class SimMotorAdapter : public rover_ports::IMotorControls {
public:
  SimMotorAdapter(rclcpp::Node::SharedPtr node);
  void set_velocity(double linear_x, double angular_z) override;
  void stop() override;

private:
  rclcpp::Node::SharedPtr node_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
};

} // namespace rover_infrastructure
