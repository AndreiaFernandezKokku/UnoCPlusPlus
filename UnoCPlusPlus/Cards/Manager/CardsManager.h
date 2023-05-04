#pragma once
#include <vector>
#include "../Card.h"
#include <optional>

class CardsManager
{
	const int MIN_TABLE_CARDS = 2;
	std::vector<Card> deck;
	std::vector<Card> table;

	bool DoesDeckHaveEnoughCardsToSend(int amountToSend);
	bool DoesTableHaveEnoughCardsToSendToDeck(int amountToSend);
	void SendCardsFromTableToDeck();

public:
	void PopulateDeckList();
	void ShuffleDeckList();

	void PlaceOneCardFromDeckInVector(std::vector<Card>& vectorToPlace);
	void PlaceAmountOfCardsFromDeckInVector(std::vector<Card>& vectorToPlace, 
		int amount);

	const std::optional<Card> GetLastCardFromTable();
	void PlaceCardOnTable(Card cardToPlaceOnTable);
	void PrintDeckAmountOfCards();
	void PrintTableAmountOfCards();
};

