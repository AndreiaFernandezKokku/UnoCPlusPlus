#include "RulesManager.h"
#include <cassert>

RulesManager::RulesManager()
{
	turnStates.emplace_back(std::make_unique<FirstTurnState>());
	turnStates.emplace_back(std::make_unique<DefaultTurnState>());
	turnStates.emplace_back(std::make_unique<JumpTurnState>());
	turnStates.emplace_back(std::make_unique<ReverseTurnState>());
	turnStates.emplace_back(
		std::make_unique<PlusTwoCardsState>(&numberOfCardsThatStacked));
	turnStates.emplace_back(
		std::make_unique<PlusFourCardsState>(&numberOfCardsThatStacked));
	currentState = 0;
}

void RulesManager::NewCardOnTable(const Card& currentTableCard)
{
	UpdateState(currentTableCard.action);
	turnStates[currentState]->NewCardOnTable(currentTableCard);

	if (currentState != 4 && currentState != 5)
	{
		assert(numberOfCardsThatStacked == 0,
			"You can only have stacked cards on states that this is permitted.");
	}
}

void RulesManager::NoNewCardOnTable()
{
	turnStates[currentState]->NoNewCardOnTable();
}

void RulesManager::UpdateState(const CardAction& currentCardAction)
{
	switch (currentCardAction)
	{
		case CardAction::Reverse:
		{
			currentState = 3;
			return;
		}
		case CardAction::Jump:
		{
			currentState = 2;
			return;
		}
		case CardAction::PlusTwo:
		{
			currentState = 4;
			return;
		}
		case CardAction::PlusFour:
		{
			currentState = 5;
			return;
		}
		default: 
		{
			currentState = 1;
			return;
		}
	}
}

const std::vector<TurnAction> RulesManager::GetCurrentTurnActionsAvailable()
{
	return turnStates[currentState]->GetCurrentTurnActionsAvailable();
}

bool RulesManager::CanCardBePlayed(const Card& card)
{
	return turnStates[currentState]->CanCardBePlayed(card);
}

int RulesManager::GetNumberOfCardsToBeBought()
{
	return numberOfCardsThatStacked;
}


