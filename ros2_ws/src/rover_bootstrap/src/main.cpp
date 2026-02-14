#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <vector>

// Core
#include "rover_core/RoverNavigator.hpp"

// Infrastructure
#include "rover_infrastructure/GazeboLidarAdapter.hpp"
#include "rover_infrastructure/IsaacDepthAdapter.hpp"
#include "rover_infrastructure/SimMotorAdapter.hpp"

// Ports
#include "rover_ports/IDistanceSensor.hpp"
#include "rover_ports/IMotorControls.hpp"

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("rover_bootstrap");

  // 1. Create Adapters (Infrastructure layer)
  // We pass the node to adapters so they can create pubs/subs
  auto motor_adapter =
      std::make_shared<rover_infrastructure::SimMotorAdapter>(node);
  auto lidar_adapter =
      std::make_shared<rover_infrastructure::GazeboLidarAdapter>(node);

  // Instantiate Isaac adapter but maybe not use it yet if not needed, or add to
  // list
  auto depth_adapter =
      std::make_shared<rover_infrastructure::IsaacDepthAdapter>(node);

  // 2. Prepare dependencies for Domain
  std::vector<std::shared_ptr<rover_ports::IDistanceSensor>> sensors;
  sensors.push_back(lidar_adapter);
  sensors.push_back(depth_adapter);

  // 3. Instantiate Core (Domain layer)
  // Dependency Injection
  auto navigator =
      std::make_shared<rover_core::RoverNavigator>(motor_adapter, sensors);

  RCLCPP_INFO(node->get_logger(),
              "Rover Bootstrap Initialized. Starting control loop...");

  // 4. Main loop
  rclcpp::Rate rate(10); // 10 Hz
  while (rclcpp::ok()) {
    rclcpp::spin_some(node);

    // Execute domain logic
    navigator->update();

    rate.sleep();
  }

  rclcpp::shutdown();
  return 0;
}
