#pragma once
#include "../DefaultTurnState.h"

class FirstTurnState : public DefaultTurnState
{
	void AddAllActions();
public:
	void NewCardOnTable(Card currentTableCard) override;
	void NoNewCardOnTable() override;
};

