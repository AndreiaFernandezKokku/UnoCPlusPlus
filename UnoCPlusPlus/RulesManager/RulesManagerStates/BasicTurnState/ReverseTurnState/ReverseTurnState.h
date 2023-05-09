#pragma once
#include "../BasicTurnState.h"

class ReverseTurnState : public BasicTurnState
{
public:
	void NewCardOnTable(Card currentTableCard) override;

	//Stopping wrong delete
	~ReverseTurnState() = default;
};

