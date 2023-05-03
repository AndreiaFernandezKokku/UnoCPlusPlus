#include "DefaultTurnAction.h"

std::vector<TurnAction> DefaultTurnAction::GetCurrentTurnActionsAvailable()
{
	return ActionsToTake;
}

void DefaultTurnAction::NewCardOnTable(Card currentTableCard)
{
	ClearAllCurrentVariables();
	UpdateCurrentColorThatCanBePlayed(currentTableCard.color);
	UpdateCurrentActionThatCanBePlayed(currentTableCard.action);
}

void DefaultTurnAction::NoNewCardOnTable()
{
	ActionsToTake.clear();
}

bool DefaultTurnAction::CanCardBePlayed(const Card& card)
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

bool DefaultTurnAction::HasPlayableColor(const Color& color)
{
	if (std::find(ColorsThatCanBePlayed.begin(), 
		ColorsThatCanBePlayed.end(), 
		color) != ColorsThatCanBePlayed.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool DefaultTurnAction::HasPlayableAction(const CardAction& action)
{
	if (std::find(CardActThatCanBePlayed.begin(),
		CardActThatCanBePlayed.end(),
		action) != CardActThatCanBePlayed.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DefaultTurnAction::UpdateCurrentColorThatCanBePlayed(
	const Color& color)
{
	if (color == Color::Any)
	{
		AddAllColors();
	}
	else
	{
		ColorsThatCanBePlayed.push_back(color);
		ColorsThatCanBePlayed.push_back(Color::Any);
	}
}

void DefaultTurnAction::AddAllColors()
{
	for (int i = 0; i < sizeof(Color); i++)
	{
		ColorsThatCanBePlayed.push_back(Color(i));
	}
}

void DefaultTurnAction::UpdateCurrentActionThatCanBePlayed(const CardAction& action)
{
	CardActThatCanBePlayed.push_back(action);
}

void DefaultTurnAction::ClearAllCurrentVariables()
{
	ColorsThatCanBePlayed.clear();
	CardActThatCanBePlayed.clear();
	ActionsToTake.clear();
}
