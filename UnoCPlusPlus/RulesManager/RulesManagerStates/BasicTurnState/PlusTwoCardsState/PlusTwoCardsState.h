#pragma once
#include "../BasicTurnState.h"

class PlusTwoCardsState : public BasicTurnState
{
	int* NumberOfStackedCards;
	Color CurrentColor;
	
public:
	PlusTwoCardsState(int* cardStackCount) : 
		BasicTurnState{},
		NumberOfStackedCards{ cardStackCount },
		CurrentColor{ Color::Any } //just to initialize the color
	{};

	void NewCardOnTable(Card currentTableCard) override;
	void NoNewCardOnTable() override;

	//Stopping wrong delete
	~PlusTwoCardsState() = default;
};

