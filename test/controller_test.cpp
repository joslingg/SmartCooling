#include <cassert>
#include <iostream>

#include "controller/SmartController.h"

using namespace std;

void testSunnyHotOccupied()
{
    SmartController controller;

    SensorData data;

    data.temperature = 36;

    data.lightLevel = 900;

    data.rainLevel = 0;

    data.occupancyState = OccupancyState::Occupied;

    SystemState state = controller.update(data);

    assert(state.weather == WeatherState::Sunny);

    assert(state.roof == RoofState::Open);

    assert(state.mist == MistState::On);

    cout << "PASS - Sunny Hot Occupied\n";
}

void testSunnyCool()
{
    SmartController controller;

    SensorData data;

    data.temperature = 28;

    data.lightLevel = 900;

    data.rainLevel = 0;

    data.occupancyState = OccupancyState::Occupied;

    SystemState state = controller.update(data);

    assert(state.weather == WeatherState::Sunny);

    assert(state.roof == RoofState::Open);

    assert(state.mist == MistState::Off);

    cout << "PASS - Sunny Cool\n";
}

void testRain()
{
    SmartController controller;

    SensorData data;

    data.temperature = 40;

    data.lightLevel = 100;

    data.rainLevel = 900;

    data.occupancyState = OccupancyState::Occupied;

    SystemState state = controller.update(data);

    assert(state.weather == WeatherState::Rainy);

    assert(state.roof == RoofState::Open);

    assert(state.mist == MistState::Off);

    cout << "PASS - Rain\n";
}

void testCloudy()
{
    SmartController controller;

    SensorData data;

    data.temperature = 28;

    data.lightLevel = 100;

    data.rainLevel = 0;

    data.occupancyState = OccupancyState::Occupied;

    SystemState state = controller.update(data);

    assert(state.weather == WeatherState::Cloudy);

    assert(state.roof == RoofState::Closed);

    assert(state.mist == MistState::Off);

    cout << "PASS - Cloudy\n";
}

void testCloudyHotOccupied()
{
    SmartController controller;

    SensorData data;

    data.temperature = 38;

    data.lightLevel = 100;

    data.rainLevel = 0;

    data.occupancyState = OccupancyState::Occupied;

    SystemState state = controller.update(data);

    assert(state.weather == WeatherState::Cloudy);

    assert(state.roof == RoofState::Closed);

    assert(state.mist == MistState::On);

    cout << "PASS - Cloudy Hot Occupied\n";
}

int main()
{
    testSunnyHotOccupied();

    testSunnyCool();

    testRain();

    testCloudy();

    testCloudyHotOccupied();

    cout << "\nAll tests passed.\n";

    return 0;
}