#include "RulesManager.h"

void RulesManager::FirstTurn()
{
	AddAllActionsAndColors();
}

void RulesManager::NewCardOnTable(Card currentTableCard)
{
	colorsThatCanBePlayed.clear();
	cardActThatCanBePlayed.clear();
	actionsToTake.clear();

	UpdateActionsBasedOnCardActions(currentTableCard);
}

void RulesManager::NoNewCardOnTable()
{
	actionsToTake.clear();
	numberOfCardsThatStacked = 0;
}

void RulesManager::UpdateActionsBasedOnCardActions(const Card& currentTableCard)
{
	switch (currentTableCard.action)
	{
		case CardAction::Reverse:
		{
			cardActThatCanBePlayed.push_back(currentTableCard.action);
			UpdateCurrentColorThatCanBePlayed(currentTableCard);
			actionsToTake.push_back(TurnAction::Reverse);
			return;
		}
		case CardAction::Jump:
		{
			cardActThatCanBePlayed.push_back(currentTableCard.action);
			UpdateCurrentColorThatCanBePlayed(currentTableCard);
			actionsToTake.push_back(TurnAction::Jumped);
			return;
		}
		case CardAction::PlusTwo:
		{
			cardActThatCanBePlayed.push_back(currentTableCard.action);
			actionsToTake.push_back(TurnAction::BuyMultipleCard);
			numberOfCardsThatStacked += 2;
			return;
		}
		default: 
		{
			UpdateCurrentColorThatCanBePlayed(currentTableCard);
			return;
		}
	}
}

void RulesManager::UpdateCurrentColorThatCanBePlayed(const Card& currentTableCard)
{
	if (currentTableCard.color == Color::Any)
	{
		AddAllColors();
	}
	else
	{
		colorsThatCanBePlayed.push_back(currentTableCard.color);
	}
}

void RulesManager::AddAllColors()
{
	for (int i = 0; i < sizeof(Color); i++)
	{
		colorsThatCanBePlayed.push_back(Color(i));
	}
}

void RulesManager::AddAllActionsAndColors()
{
	AddAllColors();
	for (int i = 0; i < sizeof(CardAction); i++)
	{
		cardActThatCanBePlayed.push_back(CardAction(i));
	}
}

const std::vector<TurnAction> RulesManager::GetCurrentTurnActionsAvailable()
{
	return actionsToTake;
}

bool RulesManager::CanCardBePlayed(const Card& card)
{
	if (HasPlayableColor(card.color))
	{
		return true;
	}
	if (HasPlayableAction(card.action))
	{
		return true;
	}
	return false;
}

int RulesManager::GetNumberOfCardsToBeBought()
{
	return numberOfCardsThatStacked;
}

bool RulesManager::HasPlayableColor(const Color& color)
{
	if (std::find(colorsThatCanBePlayed.begin(), 
		colorsThatCanBePlayed.end(), 
		color) != colorsThatCanBePlayed.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool RulesManager::HasPlayableAction(const CardAction& action)
{
	if (std::find(cardActThatCanBePlayed.begin(),
		cardActThatCanBePlayed.end(), 
		action) != cardActThatCanBePlayed.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}


