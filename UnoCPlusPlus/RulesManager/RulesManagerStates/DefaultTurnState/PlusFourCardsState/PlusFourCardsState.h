#pragma once
#include "../DefaultTurnState.h"

class PlusFourCardsState : public DefaultTurnState
{
	int* NumberOfStackedCards;
	Color CurrentColor;
	
	Color SelectColor();
	
public:
	PlusFourCardsState(int* cardStackCount) :
		DefaultTurnState{},
		NumberOfStackedCards{ cardStackCount },
		CurrentColor{ Color::Any } //just to initialize the color
	{
	};

	void NewCardOnTable(Card currentTableCard);
	void NoNewCardOnTable();
};

