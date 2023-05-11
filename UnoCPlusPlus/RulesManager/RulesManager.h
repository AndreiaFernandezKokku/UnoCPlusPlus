#pragma once
#include <optional>
#include <memory>
#include <vector>
#include "IRulesForTurnDelegate/IRulesForTurnDelegate.h"
#include "IRulesForPlayerDataSource/IRulesForPlayerDataSource.h"
#include "../Utilities/IInputVariables.h"
#include "RulesManagerStates/IRulesState.h"
#include "RulesManagerStates/BasicTurnState/DefaultTurnState/DefaultTurnState.h"
#include "RulesManagerStates/BasicTurnState/FirstTurnState/FirstTurnState.h"
#include "RulesManagerStates/BasicTurnState/JumpTurnState/JumpTurnState.h"
#include "RulesManagerStates/BasicTurnState/ReverseTurnState/ReverseTurnState.h"
#include "RulesManagerStates/BasicTurnState/PlusTwoCardsState/PlusTwoCardsState.h"
#include "RulesManagerStates/BasicTurnState/PlusFourCardsState/PlusFourCardsState.h"
#include "RulesManagerStates/BasicTurnState/PlusTwoDiscardState/PlusTwoDiscardState.h"

class RulesManager : public IRulesForTurnDelegate, public IRulesForPlayerDataSource
{
private:
	std::vector<std::unique_ptr<IRulesState>> turnStates;
	int currentStateClassIndex = 0;
	int numberOfDeckCardsThatStacked = 0;
	int numberOfTableCardsThatStacked = 0;

	int GetNewStateIndex(const CardAction& currentCardAction);

	template<typename stateClass>
	int SelectStateClassIndex()
	{
		for (int i = 0; i < turnStates.size(); i++)
		{
			if (dynamic_cast<stateClass*>(turnStates[i].get()))
			{
				return i;
			}
		}
	}

	void AssertNumberOfDeckCardsStackedIsZero();
	void AssertNumberOfTableCardsStackedIsZero();

public:
	RulesManager(IInputVariables& inputUtil);

	//IRulesForTurnManagerDelegate
	void NewCardOnTable(const Card& currentTableCard) override;
	void NoNewCardOnTable() override;
	const std::vector<TurnAction> GetCurrentTurnActionsAvailable() override;

	//IRulesForPlayerDataSource
	bool CanCardBePlayed(const Card& card) override;
	int GetNumberOfDeckCardsToBeBought() override;
	int GetNumberOfTableCardsToBeBought() override;
};

