#include <iostream>

#include "controller/SmartController.h"
#include "devices/DeviceManager.h"

using namespace std;

void simulate(
    SmartController& controller,
    DeviceManager& devices,
    float temp,
    float hum,
    uint16_t light,
    uint16_t rain,
    OccupancyState occupancy)
{
    SensorData data;

    data.temperature = temp;
    data.humidity = hum;

    data.lightLevel = light;
    data.rainLevel = rain;

    data.occupancyState = occupancy;

    SystemState state = controller.update(data);

    devices.update(data, state);

    cout << endl;
}

int main()
{
    SmartController controller;
    DeviceManager devices;

    simulate(
        controller,
        devices,
        36,
        60,
        900,
        0,
        OccupancyState::Occupied);

    simulate(
        controller,
        devices,
        28,
        60,
        900,
        0,
        OccupancyState::Occupied);

    simulate(
        controller,
        devices,
        40,
        60,
        100,
        900,
        OccupancyState::Occupied);

    simulate(
        controller,
        devices,
        26,
        60,
        100,
        0,
        OccupancyState::Occupied);

    simulate(
        controller,
        devices,
        38,
        60,
        100,
        0,
        OccupancyState::Occupied);

    // ☀️ + 🌧️
    simulate(
        controller,
        devices,
        36,
        60,
        900,
        900,
        OccupancyState::Occupied);

    return 0;
}