#pragma once

#include "models/SensorData.h"
#include "models/SystemState.h"

class SmartController
{
public:
    SystemState update(const SensorData& data);

private:
    WeatherState currentWeather = WeatherState::Cloudy;
};