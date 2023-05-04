#include "RulesManager.h"
#include <cassert>

RulesManager::RulesManager()
{
	turnActions.emplace_back(std::make_unique<FirstTurnState>());
	turnActions.emplace_back(std::make_unique<DefaultTurnState>());
	turnActions.emplace_back(std::make_unique<JumpTurnState>());
	turnActions.emplace_back(std::make_unique<ReverseTurnState>());
	turnActions.emplace_back(
		std::make_unique<PlusTwoCardsState>(&numberOfCardsThatStacked));
	currentState = 0;
}

void RulesManager::NewCardOnTable(Card currentTableCard)
{
	UpdateState(currentTableCard.action);
	turnActions[currentState]->NewCardOnTable(currentTableCard);

	if (currentState != 4)
	{
		assert(numberOfCardsThatStacked == 0,
			"You can only have stacked cards on states that this is permitted.");
	}
}

void RulesManager::NoNewCardOnTable()
{
	turnActions[currentState]->NoNewCardOnTable();
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
		default: 
		{
			currentState = 1;
			return;
		}
	}
}

const std::vector<TurnAction> RulesManager::GetCurrentTurnActionsAvailable()
{
	return turnActions[currentState]->GetCurrentTurnActionsAvailable();
}

bool RulesManager::CanCardBePlayed(const Card& card)
{
	return turnActions[currentState]->CanCardBePlayed(card);
}

int RulesManager::GetNumberOfCardsToBeBought()
{
	return numberOfCardsThatStacked;
}


