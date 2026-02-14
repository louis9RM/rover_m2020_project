#pragma once
#include "rover_ports/IDistanceSensor.hpp"
#include "rover_ports/IMotorControls.hpp"
#include <memory>
#include <vector>

namespace rover_core {

class RoverNavigator {
public:
  RoverNavigator(
      std::shared_ptr<rover_ports::IMotorControls> motors,
      std::vector<std::shared_ptr<rover_ports::IDistanceSensor>> sensors);

  void update();

private:
  std::shared_ptr<rover_ports::IMotorControls> motors_;
  std::vector<std::shared_ptr<rover_ports::IDistanceSensor>> sensors_;
  bool hazard_detected();
};

} // namespace rover_core
