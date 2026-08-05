#include "devices/DeviceManager.h"

void DeviceManager::update(
    const SensorData& data,
    const SystemState& state)
{
    roof.update(state.roof);

    mist.update(state.mist);

    display.update(data,state);
}