#pragma once
#include "../../Cards/Card.h"
#include <vector>
#include "../TurnAction/TurnAction.h"

class IRulesState
{
public:
	//Stopping wrong delete
	virtual ~IRulesState() = default;
	
	virtual std::vector<TurnAction> GetCurrentTurnActionsAvailable() = 0;
	virtual void NewCardOnTable(Card currentTableCard) = 0;
	virtual void NoNewCardOnTable() = 0;
	virtual bool CanCardBePlayed(const Card& card) = 0;
};

