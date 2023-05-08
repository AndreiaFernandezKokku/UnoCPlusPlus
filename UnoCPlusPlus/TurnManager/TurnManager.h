#pragma once
#include <vector>
#include <memory>
#include "../IPlayersManagerDelegate/IPlayersManagerDelegate.h"
#include "../RulesManager/IRulesForTurnDelegate/IRulesForTurnDelegate.h"
#include "../Cards/ICardsManagerDelegate/ICardsManagerDelegate.h"

class TurnManager
{
	std::shared_ptr<IPlayersManagerDelegate> playersManagerDel;
	std::shared_ptr<ICardsManagerDelegate> cardsManagerDel;
	std::shared_ptr<IRulesForTurnDelegate> rulesManagerDel;
	bool moveForwards = true;
	
	bool IsThereAnyPlayerWithZeroCards();
	void DealWithReverseActionIfNeeded(const std::vector<TurnAction>& gameActions);
	bool TurnActionsContainReverse(const std::vector<TurnAction>& gameActions);
	void UpdatePlayerIndex(int& playerIndex);
	void PrintCurrentTableCard();

public:
	TurnManager(std::shared_ptr<IPlayersManagerDelegate> playersManager,
		std::shared_ptr<ICardsManagerDelegate> cardsManager,
		std::shared_ptr<IRulesForTurnDelegate> rulesManager) :
		playersManagerDel{ playersManager },
		cardsManagerDel{ cardsManager },
		rulesManagerDel{ rulesManager }
	{};
	void SetupForFirstTurn();
	void StartTurns();
};

