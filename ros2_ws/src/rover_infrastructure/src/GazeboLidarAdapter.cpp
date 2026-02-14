#include "rover_infrastructure/GazeboLidarAdapter.hpp"

namespace rover_infrastructure {

GazeboLidarAdapter::GazeboLidarAdapter(rclcpp::Node::SharedPtr node)
    : node_(node), min_distance_(999.0) {
  sub_ = node_->create_subscription<sensor_msgs::msg::LaserScan>(
      "/scan", 10,
      std::bind(&GazeboLidarAdapter::scan_callback, this,
                std::placeholders::_1));
}

double GazeboLidarAdapter::read_distance() { return min_distance_.load(); }

void GazeboLidarAdapter::scan_callback(
    const sensor_msgs::msg::LaserScan::SharedPtr msg) {
  double min_d = 999.0;
  for (float r : msg->ranges) {
    if (r < min_d && r > msg->range_min) {
      min_d = r;
    }
  }
  min_distance_.store(min_d);
}

} // namespace rover_infrastructure
