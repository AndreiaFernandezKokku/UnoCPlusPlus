#pragma once
#include <iostream>
#include <vector>
#include <optional>
#include "../Cards/Card.h"
#include "TurnAction/TurnAction.h"
#include "TurnActionSelector/DefaultTurnAction/FirstTurnAction/FirstTurnAction.h"
#include "TurnActionSelector/DefaultTurnAction/DefaultTurnAction.h"
#include "TurnActionSelector/DefaultTurnAction/JumpTurnAction/JumpTurnAction.h"
#include "TurnActionSelector/DefaultTurnAction/ReverseTurnAction/ReverseTurnAction.h"
#include "TurnActionSelector/DefaultTurnAction/PlusTwoCardsAction/PlusTwoCardsAction.h"

class RulesManager
{
	//todo add uno rules
private:
	int numberOfCardsThatStacked = 0;
	std::vector<std::unique_ptr<IRulesState>> turnActions;
	int currentState = 0;

	void UpdateActionsBasedOnCardActions(const Card& currentTableCard);

public:
	RulesManager();
	//todo separate for turn manager actions

	void NewCardOnTable(Card currentTableCard);
	void NoNewCardOnTable();
	//todo serparate for player actions
	const std::vector<TurnAction> GetCurrentTurnActionsAvailable();
	bool CanCardBePlayed(const Card& card);
	int GetNumberOfCardsToBeBought();
};

