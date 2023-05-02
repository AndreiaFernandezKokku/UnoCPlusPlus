#include "TurnManager.h"

TurnManager::TurnManager()
{
	playersManager = std::make_unique<PlayersManager>();
	cardsManager = std::make_unique<CardsManager>();
}

void TurnManager::SetupForFirstTurn()
{
	playersManager->PopulateAllPlayersVector();
	playersManager->ShuffleAllPlayersList();
	cardsManager->PopulateDeckList();
	cardsManager->ShuffleDeckList();
	cardsManager->PrintDeckAmountOfCards();

	for (Player& player : playersManager->AllPlayers)
	{
		cardsManager->PlaceAmountOfCardsFromDeckInVector(
			player.GetCurrentCards(), INITIAL_CARDS);
		player.PrintCurrentCards();
	}
}

bool TurnManager::IsThereAnyPlayerWithZeroCards()
{
	for (Player& player : playersManager->AllPlayers)
	{
		if (player.GetCurrentCardsSize() <= 0)
		{
			return true;
		}
	}
	return false;
}

void TurnManager::StartTurns()
{
	while (!IsThereAnyPlayerWithZeroCards())
	{
		//todo get last card
		//check rules
		//send rules for player to start turn

	}
}


