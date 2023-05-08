#pragma once
#include "../BasicTurnState.h"

class FirstTurnState : public BasicTurnState
{
	void AddAllActions();
public:
	void NewCardOnTable(Card currentTableCard) override;
	void NoNewCardOnTable() override;
};

