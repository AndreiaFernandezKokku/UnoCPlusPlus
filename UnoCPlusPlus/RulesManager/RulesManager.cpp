#include "RulesManager.h"

RulesManager::RulesManager()
{
	turnActions.emplace_back(std::make_unique<FirstTurnAction>());
	turnActions.emplace_back(std::make_unique<DefaultTurnAction>());
	turnActions.emplace_back(std::make_unique<JumpTurnAction>());
	turnActions.emplace_back(std::make_unique<ReverseTurnAction>());
	turnActions.emplace_back(
		std::make_unique<PlusTwoCardsAction>(numberOfCardsThatStacked));
	currentState = 0;
}

void RulesManager::NewCardOnTable(Card currentTableCard)
{
	UpdateActionsBasedOnCardActions(currentTableCard);
	turnActions[currentState]->NewCardOnTable(currentTableCard);
}

void RulesManager::NoNewCardOnTable()
{
	turnActions[currentState]->NoNewCardOnTable();
}

void RulesManager::UpdateActionsBasedOnCardActions(const Card& currentTableCard)
{
	switch (currentTableCard.action)
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


