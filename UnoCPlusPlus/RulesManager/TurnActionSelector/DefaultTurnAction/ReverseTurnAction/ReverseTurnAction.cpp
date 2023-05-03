#include "ReverseTurnAction.h"

void ReverseTurnAction::NewCardOnTable(Card currentTableCard)
{
	ClearAllCurrentVariables();
	UpdateCurrentActionThatCanBePlayed(currentTableCard.action);
	UpdateCurrentColorThatCanBePlayed(currentTableCard.color);
	ActionsToTake.push_back(TurnAction::Reverse);
}
