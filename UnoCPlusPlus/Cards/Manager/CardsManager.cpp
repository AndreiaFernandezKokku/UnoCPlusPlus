#include "CardsManager.h"
#include "../Importer/Importer.h"
#include "../../Utilities/Header/RandomUtility.h"

void CardsManager::PopulateDeckList()
{
	Importer importer = Importer{};
	deck = importer.GetAllCards();
}

void CardsManager::ShuffleDeckList()
{
	RandomUtility::ShuffleVector<std::vector<Card>>(deck.begin(), deck.end());
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
			printf("Deck does not have enough cards to send. \n");
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
	int vectorEndPlusMinTableCards = -1 - MIN_TABLE_CARDS;
	deck.insert(deck.end(),
		std::make_move_iterator(table.begin()),
		std::make_move_iterator(table.end() - vectorEndPlusMinTableCards));

	table.erase(table.begin(), table.end() - vectorEndPlusMinTableCards);

	ShuffleDeckList();
}

void CardsManager::PlaceCardOnTable(Card cardToPlaceOnTable)
{
	table.push_back(cardToPlaceOnTable);
}


void CardsManager::PrintDeckAmountOfCards()
{
	printf("Deck amount of cards is: %i \n", deck.size());
}
