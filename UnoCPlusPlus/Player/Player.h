#pragma once
#include <vector>
#include <memory>
#include "../Cards/Card.h"
#include <optional>
#include "../TurnManager/ITurnManagerDelegate/ITurnManagerDelegate.h"
#include "../RulesManager/TurnAction/TurnAction.h"
#include "ActionsThatCanBeTaken/IPlayerActionsThatCanBeTaken.h"

class Player
{
	//todo add uno rules
private:
	std::vector<Card> currentCards;
	std::shared_ptr<std::string> name;
	std::vector<std::unique_ptr<IPlayerActionsThatCanBeTaken>> possibleActions;

	bool CanPlay(std::vector<TurnAction> turnAction);
	void ShowPlaceCardAction();
	void ShowObligationToBuyCard();
	void ShowBuyCardIfNoOwnedCardsIsValid();
	bool ShouldBuyMultipleCard(std::vector<TurnAction> turnAction);
	void PrintAction(int actionNumber);
	void PrintCard(const Card& cardToPrint);
	const int SelectActionToTake();

public:
	ITurnManagerDelegate* del = NULL;

	Player(std::shared_ptr<std::string> nam) :
		name{ nam }
	{};

	std::optional<Card> StartTurn(std::vector<TurnAction> turnAction);
	const char* GetName();
	std::vector<Card>& GetCurrentCards();
	const int GetCurrentCardsSize();
	void PrintCurrentCards();
};