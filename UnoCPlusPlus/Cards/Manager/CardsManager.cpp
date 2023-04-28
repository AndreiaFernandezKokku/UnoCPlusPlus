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

void CardsManager::PlaceCardFromDeckInVector(std::vector<Card>& vectorToPlace)
{
	vectorToPlace.push_back(std::move(deck.back()));
	deck.pop_back();
}

void CardsManager::PlaceAmountOfCardsFromDeckInVector(std::vector<Card>& vectorToPlace,
	int amount)
{
	vectorToPlace.insert(vectorToPlace.end(),
	std::make_move_iterator(deck.begin()),
	std::make_move_iterator(deck.begin() + amount));

	deck.erase(deck.begin(), deck.begin() + amount);
}

void CardsManager::PrintDeckAmountOfCards()
{
	printf("Deck amount of cards is: %i \n", deck.size());
}
