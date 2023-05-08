#include "CardsManager.h"
#include "../../Importer/Importer.h"
#include "../../../Utilities/Header/RandomUtility.h"
#include <cassert>

void CardsManager::Initialize()
{
	PopulateDeckList();
	ShuffleDeckList();
}

void CardsManager::PopulateDeckList()
{
	Importer importer = Importer{};
	deck = importer.GetAllCards();
	PrintDeckAmountOfCards();
}

void CardsManager::ShuffleDeckList()
{
	RandomUtility::ShuffleVector<std::vector<Card>>(deck.begin(), deck.end());
}

void CardsManager::PlaceInitialCardsInVector(std::vector<Card>&& vectorToPlace)
{
	assert(deck.size() >= INITIAL_CARDS,
		"You must initialize the deck with cards enough to give to the players");

	vectorToPlace.insert(vectorToPlace.end(),
	std::make_move_iterator(deck.begin()),
	std::make_move_iterator(deck.begin() + INITIAL_CARDS));

	deck.erase(deck.begin(), deck.begin() + INITIAL_CARDS);
}

void CardsManager::PlaceOneCardFromDeckInVector(std::vector<Card>&& vectorToPlace)
{
	if (!DoesDeckHaveEnoughCardsToSend(1)) return;

	vectorToPlace.push_back(std::move(deck.back()));
	deck.pop_back();
}

void CardsManager::PlaceAmountOfCardsFromDeckInVector(std::vector<Card>&& vectorToPlace,
	int amount)
{
	if (!DoesDeckHaveEnoughCardsToSend(amount)) return;

	vectorToPlace.insert(vectorToPlace.end(),
	std::make_move_iterator(deck.begin()),
	std::make_move_iterator(deck.begin() + amount));

	deck.erase(deck.begin(), deck.begin() + amount);
}

const std::optional<Card> CardsManager::GetLastCardFromTable()
{
	if (table.size() <= 0)
	{
		return std::nullopt;
	}
	return table.back();
}

bool CardsManager::DoesDeckHaveEnoughCardsToSend(int amountToSend)
{
	if (deck.size() < amountToSend)
	{
		if (DoesTableHaveEnoughCardsToSendToDeck(amountToSend))
		{
			SendCardsFromTableToDeck();
			return true;
		}
		else
		{
			PrintDeckAmountOfCards();
			PrintTableAmountOfCards();
			printf("Not Deck nor table have have enough cards to send. \n");
			return false;
		}
	}
	return true;
}

bool CardsManager::DoesTableHaveEnoughCardsToSendToDeck(int amountToSend)
{
	if (table.size() <= (amountToSend + MIN_TABLE_CARDS))
	{
		printf("Not enough table cards to fill deck. \n");
		return false;
	}
	return true;
}

void CardsManager::SendCardsFromTableToDeck()
{
	printf("Sending cards from table to deck. \n");
	int vectorEndPlusMinTableCards = 1 + MIN_TABLE_CARDS;
	deck.insert(deck.end(),
		std::make_move_iterator(table.begin()),
		std::make_move_iterator(table.end() - vectorEndPlusMinTableCards));

	table.erase(table.begin(), table.end() - vectorEndPlusMinTableCards);

	ShuffleDeckList();
	PrintDeckAmountOfCards();
	PrintTableAmountOfCards();
}

void CardsManager::PlaceCardOnTable(Card cardToPlaceOnTable)
{
	table.push_back(cardToPlaceOnTable);
}


void CardsManager::PrintDeckAmountOfCards()
{
	printf("Deck amount of cards is: %i \n", static_cast<int>(deck.size()));
}

void CardsManager::PrintTableAmountOfCards()
{
	printf("Table amount of cards is: %i \n", static_cast<int>(table.size()));
}