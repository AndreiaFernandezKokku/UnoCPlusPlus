#pragma once
#include <vector>
#include "../Card.h"

class CardsManager
{
	std::vector<Card> deck;
	std::vector<Card> table;

public:
	void PopulateDeckList();
	void ShuffleDeckList();
	void PlaceCardFromDeckInVector(std::vector<Card>& vectorToPlace);
	void PlaceAmountOfCardsFromDeckInVector(std::vector<Card>& vectorToPlace, 
		int amount);
	void PrintDeckAmountOfCards();
};

