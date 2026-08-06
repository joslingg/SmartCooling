#include <iostream>

#include "controller/SmartController.h"
#include "devices/DeviceManager.h"
#include "sensors/SensorManager.h"

using namespace std;

void simulate(
    SmartController& controller,
    DeviceManager& devices,
    SensorManager& sensorManager,
    const SensorData& data)
{
    sensorManager.setSimulationData(data);

    SensorData sensorData = sensorManager.read();

    SystemState state = controller.update(sensorData);

    devices.update(sensorData, state);

    cout << endl;
}

int main()
{
    SmartController controller;
    DeviceManager devices;
    SensorManager sensorManager;

    // ==========================
    // Scenario 1 : Sunny + Hot
    // ==========================

    SensorData sunnyHot;

    sunnyHot.temperature = 36;
    sunnyHot.humidity = 60;
    sunnyHot.lightLevel = 900;
    sunnyHot.rainLevel = 0;
    sunnyHot.occupancyState = OccupancyState::Occupied;

    // ==========================
    // Scenario 2 : Sunny + Cool
    // ==========================

    SensorData sunnyCool;

    sunnyCool.temperature = 28;
    sunnyCool.humidity = 60;
    sunnyCool.lightLevel = 900;
    sunnyCool.rainLevel = 0;
    sunnyCool.occupancyState = OccupancyState::Occupied;

    // ==========================
    // Scenario 3 : Rain
    // ==========================

    SensorData rainy;

    rainy.temperature = 40;
    rainy.humidity = 60;
    rainy.lightLevel = 100;
    rainy.rainLevel = 900;
    rainy.occupancyState = OccupancyState::Occupied;

    // ==========================
    // Scenario 4 : Cloudy
    // ==========================

    SensorData cloudy;

    cloudy.temperature = 26;
    cloudy.humidity = 60;
    cloudy.lightLevel = 100;
    cloudy.rainLevel = 0;
    cloudy.occupancyState = OccupancyState::Occupied;

    // ==========================
    // Scenario 5 : Cloudy + Hot
    // ==========================

    SensorData cloudyHot;

    cloudyHot.temperature = 38;
    cloudyHot.humidity = 60;
    cloudyHot.lightLevel = 100;
    cloudyHot.rainLevel = 0;
    cloudyHot.occupancyState = OccupancyState::Occupied;

    // ==========================
    // Scenario 6 : Sunny + Rain
    // ==========================

    SensorData sunnyRain;

    sunnyRain.temperature = 36;
    sunnyRain.humidity = 60;
    sunnyRain.lightLevel = 900;
    sunnyRain.rainLevel = 900;
    sunnyRain.occupancyState = OccupancyState::Occupied;

    // ==========================
    // Run Simulation
    // ==========================

    simulate(controller, devices, sensorManager, sunnyHot);

    simulate(controller, devices, sensorManager, sunnyCool);

    simulate(controller, devices, sensorManager, rainy);

    simulate(controller, devices, sensorManager, cloudy);

    simulate(controller, devices, sensorManager, cloudyHot);

    simulate(controller, devices, sensorManager, sunnyRain);

    return 0;
}