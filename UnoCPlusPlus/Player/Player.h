#pragma once
#include <vector>
#include <memory>
#include "../Cards/Card.h"
#include <optional>
#include "../TurnManager/ITurnManagerDelegate/ITurnManagerDelegate.h"
#include "../RulesManager/TurnAction/TurnAction.h"

class Player
{
	//todo add uno rules
private:
	std::vector<Card> currentCards;
	std::shared_ptr<std::string> name;
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