#pragma once
#include <vector>
#include <memory>
#include <optional>
#include "../Cards/Card.h"
#include "../TurnManager/ITurnManagerDelegate/ITurnManagerDelegate.h"
#include "../RulesManager/TurnAction/TurnAction.h"
#include "PlayerStates/IPlayerState.h"
#include "PlayerStates/DefaultState/DefaultState.h"
#include "PlayerStates/GotJumpedState/GotJumpedState.h"
#include "PlayerStates/MustBuyState/MustBuyState.h"
#include "PlayerStates/UnoWasNotCalledState/UnoWasNotCalledState.h"

class Player
{
private:
	std::vector<Card> currentCards;
	std::shared_ptr<std::string> name;
	std::vector<std::unique_ptr<IPlayerState>> possibleStates;
	bool unoWasCalledOut = false;
	int currentState = 0;

	void SelectState(std::vector<TurnAction> turnAction);
	bool GotJumped(std::vector<TurnAction> turnAction);
	bool ShouldBuyMultipleCard(std::vector<TurnAction> turnAction);

public:
	Player(std::shared_ptr<std::string> nam) :
		name{ nam }
	{};

	void InitializeStates(ITurnManagerDelegate* deleg);
	std::optional<Card> StartTurn(std::vector<TurnAction> turnAction);
	const char* GetName();
	std::vector<Card>& GetCurrentCards();
	const int GetCurrentCardsSize();
	void PrintCurrentCards();
};