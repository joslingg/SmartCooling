#pragma once

#include <stdint.h>

enum class OccupancyState
{
    Empty,
    Occupied
};

struct SensorData
{
    float temperature;
    float humidity;

    uint16_t lightLevel;
    uint16_t rainLevel;

    OccupancyState occupancyState;

    unsigned long timestamp;
};