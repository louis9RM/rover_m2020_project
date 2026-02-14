#pragma once

namespace rover_ports {

class IMotorControls {
public:
  virtual ~IMotorControls() = default;
  virtual void set_velocity(double linear_x, double angular_z) = 0;
  virtual void stop() = 0;
};

} // namespace rover_ports
