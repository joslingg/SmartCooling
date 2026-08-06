#include "sensors/SensorManager.h"

SensorData SensorManager::read()
{
    return simulatedData;
}

void SensorManager::setSimulationData(const SensorData& data)
{
    simulatedData = data;
}