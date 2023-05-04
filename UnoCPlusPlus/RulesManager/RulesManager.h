#pragma once
#include <iostream>
#include <vector>
#include <optional>
#include "../Cards/Card.h"
#include "TurnAction/TurnAction.h"
#include "TurnActionSelector/DefaultTurnState/FirstTurnState/FirstTurnState.h"
#include "TurnActionSelector/DefaultTurnState/DefaultTurnState.h"
#include "TurnActionSelector/DefaultTurnState/JumpTurnState/JumpTurnState.h"
#include "TurnActionSelector/DefaultTurnState/ReverseTurnState/ReverseTurnState.h"
#include "TurnActionSelector/DefaultTurnState/PlusTwoCardsState/PlusTwoCardsState.h"

class RulesManager
{
	//todo add uno rules
private:
	int numberOfCardsThatStacked = 0;
	std::vector<std::unique_ptr<IRulesState>> turnActions;
	int currentState = 0;

	void UpdateState(const CardAction& currentCardAction);

public:
	RulesManager();

	//todo separate for turn manager actions
	void NewCardOnTable(Card currentTableCard);
	void NoNewCardOnTable();
	const std::vector<TurnAction> GetCurrentTurnActionsAvailable();

	//todo serparate for player actions
	bool CanCardBePlayed(const Card& card);
	int GetNumberOfCardsToBeBought();
};

