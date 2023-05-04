#pragma once
#include "../DefaultTurnState.h"

class ReverseTurnState : public DefaultTurnState
{
	void NewCardOnTable(Card currentTableCard) override;
};

