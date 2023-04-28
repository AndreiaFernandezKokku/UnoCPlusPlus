#pragma once
#include <vector>
#include <memory>
#include "../Player/Manager/PlayersManager.h"
#include "../Cards/Manager/CardsManager.h"

class TurnManager
{
	std::unique_ptr<PlayersManager> playersManager;
	std::unique_ptr<CardsManager> cardsManager;

public:
	TurnManager();
	void SetupForFirstTurn();
	void StartTurns();
};

