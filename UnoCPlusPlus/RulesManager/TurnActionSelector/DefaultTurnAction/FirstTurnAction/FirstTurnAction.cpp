#include "FirstTurnAction.h"
#include <cassert>

void FirstTurnAction::AddAllActions()
{
	for (int i = 0; i < sizeof(CardAction); i++)
	{
		CardActThatCanBePlayed.push_back(CardAction(i));
	}
}

void FirstTurnAction::NewCardOnTable(Card currentTableCard)
{
	printf("Invalid state reached!");
	assert(false, "First Turn should not have a new card on the table.");
}

void FirstTurnAction::NoNewCardOnTable()
{
	AddAllColors();
	AddAllActions();
}
