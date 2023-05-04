#include "JumpTurnState.h"

void JumpTurnState::NewCardOnTable(Card currentTableCard)
{
	ClearAllCurrentVariables();
	UpdateCurrentActionThatCanBePlayed(currentTableCard.action);
	UpdateCurrentColorThatCanBePlayed(currentTableCard.color);
	ActionsToTake.push_back(TurnAction::Jumped);
}
