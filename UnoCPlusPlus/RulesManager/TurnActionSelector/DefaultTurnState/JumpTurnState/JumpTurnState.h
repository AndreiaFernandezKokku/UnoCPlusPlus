#pragma once
#include "../DefaultTurnState.h"

class JumpTurnState : public DefaultTurnState
{
	Color colorForNextTurn;
public:
	void NewCardOnTable(Card currentTableCard) override;
};

