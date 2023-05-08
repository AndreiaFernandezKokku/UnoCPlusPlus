#include "TurnManager.h"

void TurnManager::SetupForFirstTurn()
{
	rulesManagerDel->NoNewCardOnTable();
}

bool TurnManager::IsThereAnyPlayerWithZeroCards()
{
	for (Player& player : playersManagerDataSource->GetAllPlayers())
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
	int playerIndex = -1;

	while (!IsThereAnyPlayerWithZeroCards())
	{	
		std::vector<TurnAction> turnActions = 
			rulesManagerDel->GetCurrentTurnActionsAvailable();

		DealWithReverseActionIfNeeded(turnActions);
		UpdatePlayerIndex(playerIndex);

		std::optional<Card> card = 
			playersManagerDataSource->GetAllPlayers()[playerIndex].StartTurn(turnActions);

		if (card.has_value())
		{
			cardsManagerDel->PlaceCardOnTable(card.value());
			rulesManagerDel->NewCardOnTable(card.value());
		}
		else
		{
			printf("No card was placed in the table. \n");
			rulesManagerDel->NoNewCardOnTable();
		}

		PrintCurrentTableCard();
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
		playerIndex = playersManagerDataSource->GetAllPlayers().size() - 1;
		return;
	}

	if (playerIndex >= playersManagerDataSource->GetAllPlayers().size())
	{
		playerIndex = 0;
	}
}

void TurnManager::PrintCurrentTableCard()
{
	printf("\nCurrent table card: \n| %s , %s | \n",
	ColorToString[static_cast<int>(cardsManagerDel->GetLastCardFromTable()->color)],
	CardActionToString[static_cast<int>(cardsManagerDel->GetLastCardFromTable()->action)]);
}

