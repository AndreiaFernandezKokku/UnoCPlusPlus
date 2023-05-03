#pragma once
#include "../DefaultTurnAction.h"
class FirstTurnAction : public DefaultTurnAction
{
	void AddAllActions();
public:
	void NewCardOnTable(Card currentTableCard) override;
	void NoNewCardOnTable() override;
};

