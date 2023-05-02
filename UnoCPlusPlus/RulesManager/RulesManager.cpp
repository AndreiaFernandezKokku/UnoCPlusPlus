#include "RulesManager.h"

void RulesManager::NewCardOnTable(std::optional<Card> currentTableCard)
{
	colorsThatCanBePlayed.clear();
	cardActThatCanBePlayed.clear();
	actionsToTake.clear();

	if (!currentTableCard.has_value())
	{
		AddAllActionsAndColors();

		return;
	}

	UpdateActionsBasedOnCardActions(currentTableCard.value());
	UpdateCurrentCardsThatCanBePlayed(currentTableCard.value());
}

void RulesManager::NoNewCardOnTable()
{
	actionsToTake.clear();
	actionsToTake.push_back(TurnAction::CanPlayCard);
	numberOfCardsThatStacked = 0;
}


void RulesManager::UpdateActionsBasedOnCardActions(const Card& currentTableCard)
{
	switch (currentTableCard.action)
	{
		case CardAction::Reverse:
		{
			actionsToTake.push_back(TurnAction::Reverse);
			return;
		}
		case CardAction::Jump:
		{
			actionsToTake.push_back(TurnAction::Jumped);
			return;
		}
		case CardAction::PlusTwo:
		{
			actionsToTake.push_back(TurnAction::BuyMultipleCard);
			numberOfCardsThatStacked += 2;
			[[fallthrough]];
		}
		default: 
		{
			actionsToTake.push_back(TurnAction::CanPlayCard);
			return;
		}
	}
}

void RulesManager::UpdateCurrentCardsThatCanBePlayed(const Card& currentTableCard)
{
	if (currentTableCard.color == Color::Any)
	{
		AddAllColors();
	}
	else
	{
		colorsThatCanBePlayed.push_back(currentTableCard.color);
	}
	cardActThatCanBePlayed.push_back(currentTableCard.action);
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


