#include "PlusTwoDiscardState.h"

void PlusTwoDiscardState::NewCardOnTable(Card currentTableCard)
{
	ClearAllCurrentVariables();
	CurrentColor = currentTableCard.color;
	CardActThatCanBePlayed.push_back(currentTableCard.action);
	ActionsToTake.push_back(TurnAction::BuyMultipleTableCard);
	*NumberOfStackedDiscardCards += 2;
}

void PlusTwoDiscardState::NoNewCardOnTable()
{
	ActionsToTake.clear();
	*NumberOfStackedDiscardCards = 0;
	UpdateCurrentColorThatCanBePlayed(CurrentColor);
}
