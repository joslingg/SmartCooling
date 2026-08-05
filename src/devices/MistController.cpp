#include <iostream>

#include "devices/MistController.h"

using namespace std;

void MistController::update(MistState state)
{
    if(state == MistState::On)
        cout << "[Mist] ON\n";
    else
        cout << "[Mist] OFF\n";
}