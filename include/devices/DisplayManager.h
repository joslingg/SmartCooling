#pragma once

#include "models/SensorData.h"
#include "models/SystemState.h"

class DisplayManager
{
public:
    void update(
        const SensorData& data,
        const SystemState& state);
};