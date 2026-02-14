#pragma once
#include "rover_ports/IDistanceSensor.hpp"
#include <rclcpp/rclcpp.hpp>

namespace rover_infrastructure {

class IsaacDepthAdapter : public rover_ports::IDistanceSensor {
public:
  IsaacDepthAdapter(rclcpp::Node::SharedPtr node);
  double read_distance() override;
  std::string get_id() const override { return "IsaacDepth"; }

private:
  rclcpp::Node::SharedPtr node_;
};

} // namespace rover_infrastructure
