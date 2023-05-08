#include <memory>
#include "TurnManager/TurnManager.h"
#include "Cards/ICardsManagerDelegate/Manager/CardsManager.h"
#include "RulesManager/RulesManager.h"
#include "PlayersManager/PlayersManager.h"

int main()
{
    std::shared_ptr cardsManager = std::make_shared<CardsManager>();
    cardsManager->Initialize();

    std::shared_ptr rulesManager = std::make_shared<RulesManager>();
    
    std::shared_ptr playersManager = std::make_shared<PlayersManager>();
    playersManager->InitializePlayers(cardsManager, rulesManager);
    playersManager->PrintInitialPlayers();
    
    TurnManager turnManager = TurnManager(playersManager, cardsManager, rulesManager);
    turnManager.SetupForFirstTurn();
    turnManager.StartTurns();
}

