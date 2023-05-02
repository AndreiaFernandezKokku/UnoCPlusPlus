#pragma once
#include <vector>
#include <memory>
#include "../Player/Manager/PlayersManager.h"
#include "../Cards/Manager/CardsManager.h"

class TurnManager
{
	const int INITIAL_CARDS = 7;
	std::unique_ptr<PlayersManager> playersManager;
	std::unique_ptr<CardsManager> cardsManager;
	
	bool IsThereAnyPlayerWithZeroCards();

public:
	TurnManager();
	void SetupForFirstTurn();
	void StartTurns();
};

