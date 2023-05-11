#include "CardsManagerMocked.h"

void UnoUnitTest::CardsManagerMocked::PlaceInitialCardsInVector(std::vector<Card>& vectorToPlace)
{
	for (Card card : InitialCards)
	{
		vectorToPlace.push_back(card);
	}
}

void UnoUnitTest::CardsManagerMocked::PlaceOneCardFromDeckInVector(std::vector<Card>& vectorToPlace)
{
	PlaceAmountOfCardsFromDeckInVector(vectorToPlace, 1);
}

void UnoUnitTest::CardsManagerMocked::PlaceAmountOfCardsFromDeckInVector(std::vector<Card>& vectorToPlace, int amount)
{
	vectorToPlace.insert(vectorToPlace.end(),
		std::make_move_iterator(Deck.begin()),
		std::make_move_iterator(Deck.begin() + amount));

	Deck.erase(Deck.begin(), Deck.begin() + amount);
}

void UnoUnitTest::CardsManagerMocked::PlaceAmountOfCardsFromTableInVector(std::vector<Card>& vectorToPlace, int amount)
{
	vectorToPlace.insert(vectorToPlace.end(),
		std::make_move_iterator(Table.begin()),
		std::make_move_iterator(Table.begin() + amount));

	Table.erase(Table.begin(), Table.begin() + amount);
}

const std::optional<Card> UnoUnitTest::CardsManagerMocked::GetLastCardFromTable()
{
	if (Table.size() <= 0)
	{
		return std::nullopt;
	}
	return Table.back();
}

void UnoUnitTest::CardsManagerMocked::PlaceCardOnTable(Card cardToPlaceOnTable)
{
	Table.push_back(cardToPlaceOnTable);
}

int UnoUnitTest::CardsManagerMocked::PrintDeckAmountOfCards()
{
	return Deck.size();
}

int UnoUnitTest::CardsManagerMocked::PrintTableAmountOfCards()
{
	return Table.size();
}
