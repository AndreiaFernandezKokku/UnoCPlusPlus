#pragma once
#include "../DefaultTurnAction.h"

class ReverseTurnAction : public DefaultTurnAction
{
	void NewCardOnTable(Card currentTableCard) override;
};

