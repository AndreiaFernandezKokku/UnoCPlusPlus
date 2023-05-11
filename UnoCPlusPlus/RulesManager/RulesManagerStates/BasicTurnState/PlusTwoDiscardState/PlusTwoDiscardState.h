#pragma once
#include "../BasicTurnState.h"
class PlusTwoDiscardState : public BasicTurnState
{
	int* NumberOfStackedDiscardCards;
	Color CurrentColor;

public:
	PlusTwoDiscardState(int* cardStackOfDiscardCardsCount) :
		BasicTurnState{},
		NumberOfStackedDiscardCards{ cardStackOfDiscardCardsCount },
		CurrentColor{ Color::Any } //just to initialize the color
	{};

	void NewCardOnTable(Card currentTableCard) override;
	void NoNewCardOnTable() override;

	//Stopping wrong delete
	~PlusTwoDiscardState() = default;
};

