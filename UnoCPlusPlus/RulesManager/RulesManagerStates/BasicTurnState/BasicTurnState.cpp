#include "BasicTurnState.h"

std::vector<TurnAction> BasicTurnState::GetCurrentTurnActionsAvailable()
{
	return ActionsToTake;
}

void BasicTurnState::NewCardOnTable(Card currentTableCard)
{
	ClearAllCurrentVariables();
	UpdateCurrentColorThatCanBePlayed(currentTableCard.color);
	UpdateCurrentActionThatCanBePlayed(currentTableCard.action);
}

void BasicTurnState::NoNewCardOnTable()
{
	ActionsToTake.clear();
}

bool BasicTurnState::CanCardBePlayed(const Card& card)
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

bool BasicTurnState::HasPlayableColor(const Color& color)
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

bool BasicTurnState::HasPlayableAction(const CardAction& action)
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

void BasicTurnState::UpdateCurrentColorThatCanBePlayed(
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

void BasicTurnState::AddAllColors()
{
	for (int i = 0; i < static_cast<int>(Color::Count); i++)
	{
		ColorsThatCanBePlayed.push_back(Color(i));
	}
}

void BasicTurnState::UpdateCurrentActionThatCanBePlayed(const CardAction& action)
{
	CardActThatCanBePlayed.push_back(action);
}

void BasicTurnState::ClearAllCurrentVariables()
{
	ColorsThatCanBePlayed.clear();
	CardActThatCanBePlayed.clear();
	ActionsToTake.clear();
}
