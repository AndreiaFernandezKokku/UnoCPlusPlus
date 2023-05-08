#pragma once
#include "../../Cards/Card.h"
#include <vector>
#include "../TurnAction/TurnAction.h"

class IRulesForTurnDelegate
{
public:
	virtual void NewCardOnTable(const Card& currentTableCard) = 0;
	virtual void NoNewCardOnTable() = 0;
	virtual const std::vector<TurnAction> GetCurrentTurnActionsAvailable() = 0;
};