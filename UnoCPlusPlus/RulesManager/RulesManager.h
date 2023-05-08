#pragma once
#include <optional>
#include <memory>
#include <vector>
#include "IRulesForTurnDelegate/IRulesForTurnDelegate.h"
#include "IRulesForPlayerDataSource/IRulesForPlayerDataSource.h"
#include "RulesManagerStates/IRulesState.h"
#include "RulesManagerStates/DefaultTurnState/FirstTurnState/FirstTurnState.h"
#include "RulesManagerStates/DefaultTurnState/DefaultTurnState.h"
#include "RulesManagerStates/DefaultTurnState/JumpTurnState/JumpTurnState.h"
#include "RulesManagerStates/DefaultTurnState/ReverseTurnState/ReverseTurnState.h"
#include "RulesManagerStates/DefaultTurnState/PlusTwoCardsState/PlusTwoCardsState.h"
#include "RulesManagerStates/DefaultTurnState/PlusFourCardsState/PlusFourCardsState.h"

class RulesManager : public IRulesForTurnDelegate, public IRulesForPlayerDataSource
{
private:
	int numberOfCardsThatStacked = 0;
	std::vector<std::unique_ptr<IRulesState>> turnStates;
	int currentState = 0;

	void UpdateState(const CardAction& currentCardAction);

public:
	RulesManager();

	//IRulesForTurnManagerDelegate
	void NewCardOnTable(Card currentTableCard) override;
	void NoNewCardOnTable() override;
	const std::vector<TurnAction> GetCurrentTurnActionsAvailable() override;

	//IRulesForPlayerDataSource
	bool CanCardBePlayed(const Card& card) override;
	int GetNumberOfCardsToBeBought() override;
};

