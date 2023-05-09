#pragma once
#include "../ICardsManagerDelegate.h"

class CardsManager : public ICardsManagerDelegate
{
	const int MIN_TABLE_CARDS = 2;
	const int INITIAL_CARDS = 7;
	std::vector<Card> deck;
	std::vector<Card> table;

	void PopulateDeckList();
	void ShuffleDeckList();
	bool DoesDeckHaveEnoughCardsToSend(int amountToSend);
	bool DoesTableHaveEnoughCardsToSendToDeck(int amountToSend);
	void SendCardsFromTableToDeck();

public:
	void Initialize();

	void PlaceInitialCardsInVector(std::vector<Card>& vectorToPlace) override;
	void PlaceOneCardFromDeckInVector(std::vector<Card>& vectorToPlace) override;
	void PlaceAmountOfCardsFromDeckInVector(std::vector<Card>& vectorToPlace,
		int amount) override;

	const std::optional<Card> GetLastCardFromTable() override;
	void PlaceCardOnTable(Card cardToPlaceOnTable) override;
	void PrintDeckAmountOfCards() override;
	void PrintTableAmountOfCards() override;
};

