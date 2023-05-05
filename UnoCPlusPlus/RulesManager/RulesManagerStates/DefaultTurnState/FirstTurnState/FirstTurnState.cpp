#include "FirstTurnState.h"
#include <cassert>

void FirstTurnState::AddAllActions()
{
	for (int i = 0; i < static_cast<int>(CardAction::Count); i++)
	{
		CardActThatCanBePlayed.push_back(CardAction(i));
	}
}

void FirstTurnState::NewCardOnTable(Card currentTableCard)
{
	printf("Invalid state reached!");
	assert(false, "First Turn should not have a new card on the table.");
}

void FirstTurnState::NoNewCardOnTable()
{
	AddAllColors();
	AddAllActions();
}
