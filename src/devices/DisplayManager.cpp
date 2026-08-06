#include <iostream>

#include "devices/DisplayManager.h"

using namespace std;

void DisplayManager::update(
    const SensorData& data,
    const SystemState& state)
{
    cout << "========================" << endl;

    cout << "Temp     : " << data.temperature << " C" << endl;
    cout << "Humidity : " << data.humidity << " %" << endl;

    cout << "Weather  : " << weatherToString(state.weather) << endl;
    cout << "Roof     : " << roofToString(state.roof) << endl;
    cout << "Mist     : " << mistToString(state.mist) << endl;
}

string DisplayManager::weatherToString(WeatherState weather) const
{
    switch (weather)
    {
        case WeatherState::Sunny:
            return "Sunny";

        case WeatherState::Cloudy:
            return "Cloudy";

        case WeatherState::Rainy:
            return "Rainy";

        case WeatherState::SunnyRain:
            return "Sunny Rain";

        default:
            return "Unknown";
    }
}

string DisplayManager::roofToString(RoofState roof) const
{
    switch (roof)
    {
        case RoofState::Open:
            return "OPEN";

        case RoofState::Closed:
            return "CLOSED";

        default:
            return "Unknown";
    }
}

string DisplayManager::mistToString(MistState mist) const
{
    switch (mist)
    {
        case MistState::On:
            return "ON";

        case MistState::Off:
            return "OFF";

        default:
            return "Unknown";
    }
}