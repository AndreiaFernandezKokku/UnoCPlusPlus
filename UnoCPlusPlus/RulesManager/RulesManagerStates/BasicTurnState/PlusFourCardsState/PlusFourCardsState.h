#pragma once
#include "../BasicTurnState.h"
#include "../../../../Utilities/IInputVariables.h"

class PlusFourCardsState : public BasicTurnState
{
	int* NumberOfStackedCards;
	Color CurrentColor;
	IInputVariables& InputManager;
	
	Color SelectColor();
	
public:
	PlusFourCardsState(int* cardStackCount, IInputVariables& inputManager) :
		BasicTurnState{},
		NumberOfStackedCards{ cardStackCount },
		CurrentColor{ Color::Any }, //just to initialize the color
		InputManager{ inputManager }
	{};

	void NewCardOnTable(Card currentTableCard) override;
	void NoNewCardOnTable() override;

	//Stopping wrong delete
	~PlusFourCardsState() = default;
};

