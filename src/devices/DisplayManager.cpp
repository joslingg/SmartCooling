#include <iostream>

#include "devices/DisplayManager.h"

using namespace std;

void DisplayManager::update(
    const SensorData& data,
    const SystemState& state)
{
    cout << "========================\n";

    cout << "Temp : " << data.temperature << " C\n";

    cout << "Humidity : " << data.humidity << " %\n";

    cout << "Weather : ";

    switch(state.weather)
    {
        case WeatherState::Sunny:
            cout << "Sunny";
            break;

        case WeatherState::Cloudy:
            cout << "Cloudy";
            break;

        case WeatherState::Rainy:
            cout << "Rainy";
            break;

        case WeatherState::SunnyRain:
            cout << "SunnyRain";
            break;
    }

    cout << endl;
}