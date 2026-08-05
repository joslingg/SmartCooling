#include <iostream>

#include "devices/RoofController.h"

using namespace std;

void RoofController::update(RoofState state)
{
    if(state == RoofState::Open)
        cout << "[Roof] OPEN\n";
    else
        cout << "[Roof] CLOSED\n";
}