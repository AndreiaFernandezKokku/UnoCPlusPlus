#pragma once
#include "../DefaultTurnState.h"

class PlusTwoCardsState : public DefaultTurnState
{
	int* NumberOfStackedCards;
	Color CurrentColor;
	
public:
	PlusTwoCardsState(int* cardStackCount) : 
		DefaultTurnState{},
		NumberOfStackedCards{ cardStackCount },
		CurrentColor{ Color::Any } //just to initialize the color
	{};

	void NewCardOnTable(Card currentTableCard);
	void NoNewCardOnTable();

};

