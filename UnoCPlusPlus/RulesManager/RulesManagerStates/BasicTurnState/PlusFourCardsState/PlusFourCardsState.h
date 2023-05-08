#pragma once
#include "../BasicTurnState.h"

class PlusFourCardsState : public BasicTurnState
{
	int* NumberOfStackedCards;
	Color CurrentColor;
	
	Color SelectColor();
	
public:
	PlusFourCardsState(int* cardStackCount) :
		BasicTurnState{},
		NumberOfStackedCards{ cardStackCount },
		CurrentColor{ Color::Any } //just to initialize the color
	{
	};

	void NewCardOnTable(Card currentTableCard);
	void NoNewCardOnTable();
};

