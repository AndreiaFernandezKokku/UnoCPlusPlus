#include "PlusTwoCardsState.h"

void PlusTwoCardsState::NewCardOnTable(Card currentTableCard)
{
	ClearAllCurrentVariables();
	CurrentColor = currentTableCard.color;
	CardActThatCanBePlayed.push_back(currentTableCard.action);
	CardActThatCanBePlayed.push_back(CardAction::PlusFour);
	ActionsToTake.push_back(TurnAction::BuyMultipleCard);
	*NumberOfStackedCards += 2;
}

void PlusTwoCardsState::NoNewCardOnTable()
{
	ActionsToTake.clear();
	*NumberOfStackedCards = 0; 
	UpdateCurrentColorThatCanBePlayed(CurrentColor);
}
