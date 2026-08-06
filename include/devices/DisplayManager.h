#pragma once

#include <string>

#include "models/SensorData.h"
#include "models/SystemState.h"

class DisplayManager
{
public:
    void update(
        const SensorData& data,
        const SystemState& state);

private:
    std::string weatherToString(WeatherState weather) const;
    std::string roofToString(RoofState roof) const;
    std::string mistToString(MistState mist) const;
};