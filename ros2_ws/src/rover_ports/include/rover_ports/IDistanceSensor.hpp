#pragma once
#include <string>

namespace rover_ports {

class IDistanceSensor {
public:
    virtual ~IDistanceSensor() = default;
    virtual double read_distance() = 0;
    virtual std::string get_id() const = 0;
};

}
