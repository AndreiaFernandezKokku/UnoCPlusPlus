#include "PlusTwoCardsAction.h"

void PlusTwoCardsAction::NewCardOnTable(Card currentTableCard)
{
	ClearAllCurrentVariables();
	CurrentColor = currentTableCard.color;
	CardActThatCanBePlayed.push_back(currentTableCard.action);
	ActionsToTake.push_back(TurnAction::BuyMultipleCard);
	NumberOfStackedCards += 2; //todo buy cards is wrong!!
}

void PlusTwoCardsAction::NoNewCardOnTable()
{
	ActionsToTake.clear();
	NumberOfStackedCards = 0; 
	UpdateCurrentColorThatCanBePlayed(CurrentColor);
}
