#pragma once

#include "models/SensorData.h"

class SensorManager
{
public:
    SensorData read();

    void setSimulationData(const SensorData& data);

private:
    SensorData simulatedData;
};