#pragma once
#include "../BasicTurnState.h"

class JumpTurnState : public BasicTurnState
{
	Color colorForNextTurn;
public:
	void NewCardOnTable(Card currentTableCard) override;

	//Stopping wrong delete
	~JumpTurnState() = default;
};

