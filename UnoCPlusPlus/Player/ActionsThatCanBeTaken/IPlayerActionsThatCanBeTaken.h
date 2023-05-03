#pragma once
#include <optional>
#include <vector>
#include "../../Cards/Card.h"
#include "../../TurnManager/ITurnManagerDelegate/ITurnManagerDelegate.h"

class IPlayerActionsThatCanBeTaken
{
protected:
	ITurnManagerDelegate* Del;
	std::vector<Card>& CurrentCards;

	IPlayerActionsThatCanBeTaken(ITurnManagerDelegate* del,
		std::vector<Card>& currentCards) :
		Del{ del }, CurrentCards{ currentCards }
	{};

public:
	virtual std::optional<Card> TakeAction() = 0;
};

