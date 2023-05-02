#pragma once
#include <vector>
#include "../Card.h"
#include <optional>

class CardsManager
{
	const int MIN_TABLE_CARDS = 2;
	std::vector<Card> deck;
	std::vector<Card> table;

	//todo test
	bool DoesDeckHaveEnoughCardsToSend(int amountToSend);
	bool DoesTableHaveEnoughCardsToSendToDeck(int amountToSend);
	void SendCardsFromTableToDeck();

public:
	void PopulateDeckList();
	void ShuffleDeckList();
	// here we move
	void PlaceOneCardFromDeckInVector(std::vector<Card>& vectorToPlace);
	void PlaceAmountOfCardsFromDeckInVector(std::vector<Card>& vectorToPlace, 
		int amount);
	// /here we move
	// here we copy
	const std::optional<Card> GetLastCardFromTable();
	void PlaceCardOnTable(std::optional<Card> cardToPlaceOnTable);
	// /here we copy
	void PrintDeckAmountOfCards();
};

