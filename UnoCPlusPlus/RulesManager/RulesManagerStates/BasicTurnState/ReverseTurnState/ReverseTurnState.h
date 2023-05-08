#pragma once
#include "../BasicTurnState.h"

class ReverseTurnState : public BasicTurnState
{
	void NewCardOnTable(Card currentTableCard) override;
};

