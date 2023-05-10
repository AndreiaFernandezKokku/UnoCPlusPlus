#include <memory>
#include "TurnManager/TurnManager.h"
#include "Cards/ICardsManagerDelegate/Manager/CardsManager.h"
#include "RulesManager/RulesManager.h"
#include "PlayersManager/PlayersManager.h"
#include "Utilities/ConcreteClasses/Header/RandomUtility.h"
#include "Utilities/ConcreteClasses/Header/InputVariablesManager.h"

int main()
{
    RandomUtility random = RandomUtility{};
    InputVariablesManager inputVariables = InputVariablesManager{};
    
    std::shared_ptr cardsManager = std::make_shared<CardsManager>(random);
    cardsManager->Initialize();

    std::shared_ptr rulesManager = std::make_shared<RulesManager>();
    
    std::shared_ptr playersManager = 
        std::make_shared<PlayersManager>(inputVariables, random);

    playersManager->InitializePlayers(cardsManager, rulesManager);
    playersManager->PrintInitialPlayers();
    
    TurnManager turnManager = TurnManager(playersManager, cardsManager, rulesManager);
    turnManager.SetupForFirstTurn();
    turnManager.StartTurns();
}

