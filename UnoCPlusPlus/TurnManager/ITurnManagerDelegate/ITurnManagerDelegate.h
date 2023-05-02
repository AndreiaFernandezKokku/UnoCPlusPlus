#pragma once
#include <functional>
#include "../../Cards/Card.h"

class ITurnManagerDelegate
{
public:
	std::function<bool(const Card&)> CanCardBePlayed = 0;
	std::function<void(std::vector<Card>& vectorToPlace,
		int amount)> PlaceAmountOfDeckCardsInVector = 0;
	std::function<void(std::vector<Card>& vectorToPlace)>
		PlaceOneDeckCardInVector = 0;
	std::function<int()> NumberOfCardsToBeBought = 0;
};