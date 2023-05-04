#include "DefaultTurnState.h"

std::vector<TurnAction> DefaultTurnState::GetCurrentTurnActionsAvailable()
{
	return ActionsToTake;
}

void DefaultTurnState::NewCardOnTable(Card currentTableCard)
{
	ClearAllCurrentVariables();
	UpdateCurrentColorThatCanBePlayed(currentTableCard.color);
	UpdateCurrentActionThatCanBePlayed(currentTableCard.action);
}

void DefaultTurnState::NoNewCardOnTable()
{
	ActionsToTake.clear();
}

bool DefaultTurnState::CanCardBePlayed(const Card& card)
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

bool DefaultTurnState::HasPlayableColor(const Color& color)
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

bool DefaultTurnState::HasPlayableAction(const CardAction& action)
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

void DefaultTurnState::UpdateCurrentColorThatCanBePlayed(
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

void DefaultTurnState::AddAllColors()
{
	for (int i = 0; i <= sizeof(Color); i++)
	{
		ColorsThatCanBePlayed.push_back(Color(i));
	}
}

void DefaultTurnState::UpdateCurrentActionThatCanBePlayed(const CardAction& action)
{
	CardActThatCanBePlayed.push_back(action);
}

void DefaultTurnState::ClearAllCurrentVariables()
{
	ColorsThatCanBePlayed.clear();
	CardActThatCanBePlayed.clear();
	ActionsToTake.clear();
}
