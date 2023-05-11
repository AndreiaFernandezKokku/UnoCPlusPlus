#include "CardsManager.h"
#include "../../Importer/Importer.h"
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
	randomUtility.ShuffleVector<std::vector<Card>>(deck.begin(), deck.end());
}

void CardsManager::PlaceInitialCardsInVector(std::vector<Card>& vectorToPlace)
{
	assert(deck.size() >= INITIAL_CARDS,
		"You must initialize the deck with cards enough to give to the players");

	PlaceAmountOfCardsFromDeckInVector(vectorToPlace, INITIAL_CARDS);
}

void CardsManager::PlaceOneCardFromDeckInVector(std::vector<Card>& vectorToPlace)
{
	if (!DoesDeckHaveEnoughCardsToSend(1)) return;

	vectorToPlace.push_back(std::move(deck.back()));
	deck.pop_back();
}

void CardsManager::PlaceAmountOfCardsFromDeckInVector(std::vector<Card>& vectorToPlace,
	int amount)
{
	if (!DoesDeckHaveEnoughCardsToSend(amount)) return;

	vectorToPlace.insert(vectorToPlace.end(),
	std::make_move_iterator(deck.begin()),
	std::make_move_iterator(deck.begin() + amount));

	deck.erase(deck.begin(), deck.begin() + amount);
}

void CardsManager::PlaceAmountOfCardsFromTableInVector(std::vector<Card>& vectorToPlace, 
	int amount)
{
	if (DoesTableHaveEnoughCardsToSend(amount))
	{
		for (int i = 0; i < amount; i++)
		{
			int cardIndex = randomUtility.RandRange(0, table.size() - MIN_TABLE_CARDS);
			vectorToPlace.push_back(table[cardIndex]);
			table.erase(table.begin() + cardIndex);
		}
	}
	else
	{
		printf("Sending cards from deck.\n");
		PlaceAmountOfCardsFromDeckInVector(vectorToPlace, amount);
	}
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
		printf("Not enough deck cards to send.\n");
		if (DoesTableHaveEnoughCardsToSend(amountToSend))
		{
			SendCardsFromTableToDeck();
			return true;
		}
		else
		{
			PrintDeckAmountOfCards();
			PrintTableAmountOfCards();
			printf("Not Deck nor table have have enough cards to send. \nThe player will not receive the cards.\n");
			return false;
		}
	}
	return true;
}

bool CardsManager::DoesTableHaveEnoughCardsToSend(int amountToSend)
{
	if (table.size() < (amountToSend + MIN_TABLE_CARDS))
	{
		printf("Not enough table cards to send. \n");
		return false;
	}
	return true;
}

void CardsManager::SendCardsFromTableToDeck()
{
	printf("Sending cards from table to deck. \nBefore: \n");
	PrintDeckAmountOfCards();
	PrintTableAmountOfCards();

	int vectorEndPlusMinTableCards = 1 + MIN_TABLE_CARDS;
	deck.insert(deck.end(),
		std::make_move_iterator(table.begin()),
		std::make_move_iterator(table.end() - vectorEndPlusMinTableCards));

	table.erase(table.begin(), table.end() - vectorEndPlusMinTableCards);

	ShuffleDeckList();
	printf("After: \n");
	PrintDeckAmountOfCards();
	PrintTableAmountOfCards();
}

void CardsManager::PlaceCardOnTable(Card cardToPlaceOnTable)
{
	table.push_back(cardToPlaceOnTable);
}

int CardsManager::PrintDeckAmountOfCards()
{
	printf("Deck amount of cards is: %i \n", static_cast<int>(deck.size()));
	return deck.size();
}

int CardsManager::PrintTableAmountOfCards()
{
	printf("Table amount of cards is: %i \n", static_cast<int>(table.size()));
	return table.size();
}