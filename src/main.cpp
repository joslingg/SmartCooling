#include <iostream>

#include "controller/SmartController.h"

using namespace std;

void simulate(
    SmartController& controller,
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

    std::cout << "=================================\n";

    std::cout << "Temp : " << temp << "\n";

    std::cout << "Light: " << light << "\n";

    std::cout << "Rain : " << rain << "\n";

    std::cout << "Occupied : "
              << (occupancy == OccupancyState::Occupied ? "YES" : "NO")
              << "\n\n";

    std::cout << "Weather : ";

    switch(state.weather)
    {
        case WeatherState::Sunny:
            std::cout << "Sunny";
            break;

        case WeatherState::Cloudy:
            std::cout << "Cloudy";
            break;

        case WeatherState::Rainy:
            std::cout << "Rainy";
            break;

        case WeatherState::SunnyRain:
            cout << "Sunny Rain";
            break;
    }

    std::cout << "\n";

    std::cout << "Roof : "
              << (state.roof == RoofState::Open ? "OPEN" : "CLOSED")
              << "\n";

    std::cout << "Mist : "
              << (state.mist == MistState::On ? "ON" : "OFF")
              << "\n";
}

int main()
{
    SmartController controller;

    simulate(controller,36,60,900,0,OccupancyState::Occupied);

    simulate(controller,28,60,900,0,OccupancyState::Occupied);

    simulate(controller,40,60,100,900,OccupancyState::Occupied);

    simulate(controller,26,60,100,0,OccupancyState::Occupied);

    simulate(controller,38,60,100,0,OccupancyState::Occupied);

    simulate(controller,36,60,900,900,OccupancyState::Occupied);

    return 0;
}