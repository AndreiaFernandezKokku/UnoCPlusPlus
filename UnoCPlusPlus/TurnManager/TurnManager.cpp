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
			player.GetCurrentCards(), 7);
		player.PrintCurrentCards();
	}
	cardsManager->PrintDeckAmountOfCards();
}

void TurnManager::StartTurns()
{

}


