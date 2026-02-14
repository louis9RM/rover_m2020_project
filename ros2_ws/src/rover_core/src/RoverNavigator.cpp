#include "rover_core/RoverNavigator.hpp"
#include <iostream>

namespace rover_core {

RoverNavigator::RoverNavigator(
    std::shared_ptr<rover_ports::IMotorControls> motors,
    std::vector<std::shared_ptr<rover_ports::IDistanceSensor>> sensors)
    : motors_(motors), sensors_(sensors) {}

void RoverNavigator::update() {
  if (hazard_detected()) {
    motors_->stop();
    // Simple avoid logic: turn
    motors_->set_velocity(0.0, 0.5);
  } else {
    // Move forward
    motors_->set_velocity(0.5, 0.0);
  }
}

bool RoverNavigator::hazard_detected() {
  for (auto &sensor : sensors_) {
    if (sensor->read_distance() < 1.0) { // Threshold
      return true;
    }
  }
  return false;
}

} // namespace rover_core
