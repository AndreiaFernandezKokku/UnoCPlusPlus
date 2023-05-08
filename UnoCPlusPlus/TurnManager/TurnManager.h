#pragma once
#include <vector>
#include <memory>
#include "../PlayersManager/IPlayersManagerDataSource/IPlayersManagerDataSource.h"
#include "../RulesManager/IRulesForTurnDelegate/IRulesForTurnDelegate.h"
#include "../Cards/ICardsManagerDelegate/ICardsManagerDelegate.h"

class TurnManager
{
	std::shared_ptr<IPlayersManagerDataSource> playersManagerDataSource;
	std::shared_ptr<ICardsManagerDelegate> cardsManagerDel;
	std::shared_ptr<IRulesForTurnDelegate> rulesManagerDel;
	bool moveForwards = true;
	
	bool IsThereAnyPlayerWithZeroCards();
	void DealWithReverseActionIfNeeded(const std::vector<TurnAction>& gameActions);
	bool TurnActionsContainReverse(const std::vector<TurnAction>& gameActions);
	void UpdatePlayerIndex(int& playerIndex);
	void PrintCurrentTableCard();

public:
	TurnManager(std::shared_ptr<IPlayersManagerDataSource> playersManager,
		std::shared_ptr<ICardsManagerDelegate> cardsManager,
		std::shared_ptr<IRulesForTurnDelegate> rulesManager) :
		playersManagerDataSource{ playersManager },
		cardsManagerDel{ cardsManager },
		rulesManagerDel{ rulesManager }
	{};
	void SetupForFirstTurn();
	void StartTurns();
};

