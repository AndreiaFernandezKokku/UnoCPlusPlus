#pragma once
#include "../DefaultTurnAction.h"

class PlusTwoCardsAction : public DefaultTurnAction
{
	int* NumberOfStackedCards;
	Color CurrentColor;
	
public:
	PlusTwoCardsAction(int* cardStackCount) : 
		DefaultTurnAction{},
		NumberOfStackedCards{ cardStackCount },
		CurrentColor{ Color::Any } //just to initialize the color
	{};

	void NewCardOnTable(Card currentTableCard);
	void NoNewCardOnTable();

};

