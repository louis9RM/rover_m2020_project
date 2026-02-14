#include "rover_infrastructure/IsaacDepthAdapter.hpp"

namespace rover_infrastructure {
IsaacDepthAdapter::IsaacDepthAdapter(rclcpp::Node::SharedPtr node)
    : node_(node) {}
double IsaacDepthAdapter::read_distance() { return 5.0; } // Mocked
} // namespace rover_infrastructure
