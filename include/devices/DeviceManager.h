#pragma once

#include "models/SensorData.h"
#include "models/SystemState.h"

#include "devices/RoofController.h"
#include "devices/MistController.h"
#include "devices/DisplayManager.h"

class DeviceManager
{
public:
    void update(
        const SensorData& data,
        const SystemState& state);

private:
    RoofController roof;
    MistController mist;
    DisplayManager display;
};