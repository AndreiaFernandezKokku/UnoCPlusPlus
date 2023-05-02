#include "RulesManager.h"

void RulesManager::UpdateValidActions(std::optional<Card> currentTableCard)
{
	colorsThatCanBePlayed.clear();
	cardActThatCanBePlayed.clear();
	actionsToTake.clear();


	//todo add stacked cards
	//Todo add actions for turn
	if (!currentTableCard.has_value())
	{
		AddAllActionsAndColors();
		numberOfCardsThatStacked = 0;
		return;
	}

	UpdateActionsBasedOnCardActions(currentTableCard.value());


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

bool RulesManager::CanCardBePlayed(const Card& card)
{
	if (HasPlayableColor(card))
	{
		return true;
	}
	if (HasPlayableAction(card))
	{
		return true;
	}
	return false;
}

bool RulesManager::HasPlayableColor(const Card& card)
{
	if (std::find(colorsThatCanBePlayed.begin(), 
		colorsThatCanBePlayed.end(), 
		card.color) != colorsThatCanBePlayed.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool RulesManager::HasPlayableAction(const Card& card)
{
	if (std::find(cardActThatCanBePlayed.begin(),
		cardActThatCanBePlayed.end(), 
		card.action) != cardActThatCanBePlayed.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}


