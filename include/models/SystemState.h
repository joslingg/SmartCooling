#pragma once

enum class WeatherState
{
    Sunny,
    Cloudy,
    Rainy,
    SunnyRain
};

enum class RoofState
{
    Open,
    Closed
};

enum class MistState
{
    On,
    Off
};

struct SystemState
{
    WeatherState weather;

    RoofState roof;

    MistState mist;
};