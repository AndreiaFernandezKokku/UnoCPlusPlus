#pragma once
#include "../DefaultTurnAction.h"

class JumpTurnAction : public DefaultTurnAction
{
	Color colorForNextTurn;
public:
	void NewCardOnTable(Card currentTableCard) override;
};

