#pragma once
#include <vector>
#include <memory>
#include "../Player/Manager/PlayersManager.h"
#include "../Cards/Manager/CardsManager.h"
#include "../RulesManager/RulesManager.h"
#include "ITurnManagerDelegate/ITurnManagerDelegate.h"

class TurnManager : public ITurnManagerDelegate
{
	const int INITIAL_CARDS = 7;
	std::unique_ptr<PlayersManager> playersManager;
	std::unique_ptr<CardsManager> cardsManager;
	RulesManager rulesManager;
	bool moveForwards = true;
	
	bool IsThereAnyPlayerWithZeroCards();
	void DealWithReverseActionIfNeeded(const std::vector<TurnAction>& gameActions);
	bool TurnActionsContainReverse(const std::vector<TurnAction>& gameActions);
	void UpdatePlayerIndex(int& playerIndex);
	void PrintCurrentTableCard();

public:
	TurnManager();
	void SetupForFirstTurn();
	void StartTurns();
};

