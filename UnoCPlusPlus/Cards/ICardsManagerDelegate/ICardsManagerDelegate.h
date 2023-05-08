#pragma once
#include "../Card.h"
#include <vector>
#include <optional>

class ICardsManagerDelegate
{
public:
	virtual void PlaceInitialCardsInVector(
		std::vector<Card>&& vectorToPlace) = 0;
	virtual void PlaceOneCardFromDeckInVector(
		std::vector<Card>&& vectorToPlace) = 0;
	virtual void PlaceAmountOfCardsFromDeckInVector(
		std::vector<Card>&& vectorToPlace,
		int amount) = 0;

	virtual const std::optional<Card> GetLastCardFromTable() = 0;
	virtual void PlaceCardOnTable(Card cardToPlaceOnTable) = 0;
	virtual void PrintDeckAmountOfCards() = 0;
	virtual void PrintTableAmountOfCards() = 0;
};