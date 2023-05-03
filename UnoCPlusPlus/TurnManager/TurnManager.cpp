#include "TurnManager.h"

TurnManager::TurnManager()
{
	playersManager = std::make_unique<PlayersManager>();
	cardsManager = std::make_unique<CardsManager>();
	rulesManager = RulesManager();

	//todo maybe move these actions to their respective owners and just get delegates
	CanCardBePlayed = [&] (const Card& card) 
	{ 
		return rulesManager.CanCardBePlayed(card); 
	};

	PlaceAmountOfDeckCardsInVector = [&] (std::vector<Card>& vectorToPlace,
		int amount)
	{
		cardsManager->PlaceAmountOfCardsFromDeckInVector(vectorToPlace, amount);
	};

	PlaceOneDeckCardInVector = [&] (std::vector<Card>& vectorToPlace)
	{
		cardsManager->PlaceOneCardFromDeckInVector(vectorToPlace);
	};

	NumberOfCardsToBeBought = [&] ()
	{
		return rulesManager.GetNumberOfCardsToBeBought();
	};
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
		player.del = this;
	}
}

bool TurnManager::IsThereAnyPlayerWithZeroCards()
{
	for (Player& player : playersManager->AllPlayers)
	{
		if (player.GetCurrentCardsSize() <= 0)
		{
			printf("Player %s has won! \n", player.GetName());
			return true;
		}
	}
	return false;
}

void TurnManager::StartTurns()
{
	rulesManager.FirstTurn();
	int playerIndex = -1;
	while (!IsThereAnyPlayerWithZeroCards())
	{
		std::vector<TurnAction> turnActions = 
			rulesManager.GetCurrentTurnActionsAvailable();

		DealWithReverseActionIfNeeded(turnActions);
		UpdatePlayerIndex(playerIndex);

		std::optional<Card> card = 
			playersManager->AllPlayers[playerIndex].StartTurn(turnActions);

		if (card.has_value())
		{
			cardsManager->PlaceCardOnTable(card.value());
			rulesManager.NewCardOnTable(card.value());
		}
		else
		{
			printf("No card was placed in the table. \n");
			rulesManager.NoNewCardOnTable();
		}
	}
}

void TurnManager::DealWithReverseActionIfNeeded(const std::vector<TurnAction>& gameActions)
{
	if (TurnActionsContainReverse(gameActions))
	{
		moveForwards = !moveForwards;
	}
}

bool TurnManager::TurnActionsContainReverse(const std::vector<TurnAction>& gameActions)
{
	if (std::find(gameActions.begin(), gameActions.end(),
		TurnAction::Reverse) != gameActions.end())
	{
		return true;
	}
	else return false;
}

void TurnManager::UpdatePlayerIndex(int& playerIndex)
{
	if (moveForwards)
	{
		playerIndex += 1;
	}
	else
	{
		playerIndex -= 1;
	}

	if (playerIndex < 0)
	{
		playerIndex = playersManager->AllPlayers.size() - 1;
		return;
	}

	if (playerIndex >= playersManager->AllPlayers.size())
	{
		playerIndex = 0;
	}
}

