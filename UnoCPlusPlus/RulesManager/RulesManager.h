#pragma once
#include <iostream>
#include <vector>
#include <optional>
#include "../Cards/Card.h"
#include "TurnAction/TurnAction.h"
#include "RulesManagerStates/DefaultTurnState/FirstTurnState/FirstTurnState.h"
#include "RulesManagerStates/DefaultTurnState/DefaultTurnState.h"
#include "RulesManagerStates/DefaultTurnState/JumpTurnState/JumpTurnState.h"
#include "RulesManagerStates/DefaultTurnState/ReverseTurnState/ReverseTurnState.h"
#include "RulesManagerStates/DefaultTurnState/PlusTwoCardsState/PlusTwoCardsState.h"

class RulesManager
{
	//todo add uno rules
private:
	int numberOfCardsThatStacked = 0;
	std::vector<std::unique_ptr<IRulesState>> turnStates;
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

