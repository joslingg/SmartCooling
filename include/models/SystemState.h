#pragma once

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
    RoofState roof;
    MistState mist;
};