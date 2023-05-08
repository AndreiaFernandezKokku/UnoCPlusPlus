#pragma once
#include <vector>
#include <memory>
#include <optional>
#include "../RulesManager/IRulesForPlayerDataSource/IRulesForPlayerDataSource.h"
#include "../Cards/ICardsManagerDelegate/ICardsManagerDelegate.h"
#include "../Cards/Card.h"
#include "../RulesManager/TurnAction/TurnAction.h"
#include "PlayerStates/IPlayerState.h"
#include "PlayerStates/DefaultState/DefaultState.h"
#include "PlayerStates/GotJumpedState/GotJumpedState.h"
#include "PlayerStates/MustBuyState/MustBuyState.h"
#include "PlayerStates/UnoWasNotCalledState/UnoWasNotCalledState.h"

class Player
{
private:
	std::shared_ptr<std::vector<Card>> sharedPtrCurrentCards;
	std::shared_ptr<std::string> name;
	std::vector<std::unique_ptr<IPlayerState>> possibleStates;
	std::shared_ptr<bool> unoWasCalledOutPtr;
	int currentState = 0;

	void SelectState(std::vector<TurnAction> turnAction);
	bool GotJumped(std::vector<TurnAction> turnAction);
	bool ShouldBuyMultipleCard(std::vector<TurnAction> turnAction);

public:
	Player(std::shared_ptr<std::string> nam, 
		std::shared_ptr<ICardsManagerDelegate> cardsManager, 
		std::shared_ptr<IRulesForPlayerDataSource> rulesDataSource) :
		name{ nam }
	{
		InitializeStates(cardsManager, rulesDataSource);
	};

	void InitializeStates(std::shared_ptr<ICardsManagerDelegate> cardsManagerDel,
		std::shared_ptr<IRulesForPlayerDataSource> rulesDataSource);

	std::optional<Card> StartTurn(std::vector<TurnAction> turnAction);
	const char* GetName();
	const int GetCurrentCardsSize();
	void PrintCurrentCards();
};