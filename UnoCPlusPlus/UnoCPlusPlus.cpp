#include <iostream>
#include "TurnManager/TurnManager.h"

int main()
{
    TurnManager turnManager = TurnManager{};
    turnManager.SetupForFirstTurn();
    turnManager.StartTurns();
}

