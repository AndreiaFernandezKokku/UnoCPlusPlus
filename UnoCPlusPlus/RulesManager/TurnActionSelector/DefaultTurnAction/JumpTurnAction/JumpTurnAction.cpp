#include "JumpTurnAction.h"

void JumpTurnAction::NewCardOnTable(Card currentTableCard)
{
	ClearAllCurrentVariables();
	UpdateCurrentActionThatCanBePlayed(currentTableCard.action);
	UpdateCurrentColorThatCanBePlayed(currentTableCard.color);
	ActionsToTake.push_back(TurnAction::Jumped);
}
