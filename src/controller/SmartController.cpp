#include "controller/SmartController.h"
#include "config/Config.h"

SystemState SmartController::update(const SensorData& data)
{
    SystemState state;

    bool sunny = false;
    bool raining = data.rainLevel >= Config::RAIN_THRESHOLD;

    //---------------------------------
    // Hysteresis cho ánh sáng
    //---------------------------------

    if (currentWeather == WeatherState::Sunny ||
        currentWeather == WeatherState::SunnyRain)
    {
        sunny = data.lightLevel > Config::SUN_OFF_THRESHOLD;
    }
    else
    {
        sunny = data.lightLevel > Config::SUN_ON_THRESHOLD;
    }

    //---------------------------------
    // Weather
    //---------------------------------

    if (sunny && raining)
    {
        currentWeather = WeatherState::SunnyRain;
    }
    else if (raining)
    {
        currentWeather = WeatherState::Rainy;
    }
    else if (sunny)
    {
        currentWeather = WeatherState::Sunny;
    }
    else
    {
        currentWeather = WeatherState::Cloudy;
    }

    state.weather = currentWeather;

    //---------------------------------
    // Roof
    //---------------------------------

    if (sunny || raining)
        state.roof = RoofState::Open;
    else
        state.roof = RoofState::Closed;

    //---------------------------------
    // Mist
    //---------------------------------

    if (!raining &&
        data.temperature >= Config::HOT_TEMP &&
        data.occupancyState == OccupancyState::Occupied)
    {
        state.mist = MistState::On;
    }
    else
    {
        state.mist = MistState::Off;
    }

    return state;
}