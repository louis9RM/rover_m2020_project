#pragma once
#include "rover_ports/IDistanceSensor.hpp"
#include <atomic>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>

namespace rover_infrastructure {

class GazeboLidarAdapter : public rover_ports::IDistanceSensor {
public:
  GazeboLidarAdapter(rclcpp::Node::SharedPtr node);
  double read_distance() override;
  std::string get_id() const override { return "GazeboLidar"; }

private:
  void scan_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg);
  rclcpp::Node::SharedPtr node_;
  rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr sub_;
  std::atomic<double> min_distance_;
};

} // namespace rover_infrastructure
