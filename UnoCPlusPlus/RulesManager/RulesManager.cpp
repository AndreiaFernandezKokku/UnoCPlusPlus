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
	currentStateClassIndex = SelectStateClassIndex<FirstTurnState>();
}

void RulesManager::NewCardOnTable(const Card& currentTableCard)
{
	currentStateClassIndex = GetNewStateIndex(currentTableCard.action);
	turnStates[currentStateClassIndex]->NewCardOnTable(currentTableCard);
}

void RulesManager::NoNewCardOnTable()
{
	turnStates[currentStateClassIndex]->NoNewCardOnTable();
}

int RulesManager::GetNewStateIndex(const CardAction& currentCardAction)
{
	switch (currentCardAction)
	{
		case CardAction::Reverse:
		{
			AssertNumberOfCardsStackedIsZero();
			return SelectStateClassIndex<ReverseTurnState>();
		}
		case CardAction::Jump:
		{
			AssertNumberOfCardsStackedIsZero();
			return SelectStateClassIndex<JumpTurnState>();
		}
		case CardAction::PlusTwo:
		{
			return SelectStateClassIndex<PlusTwoCardsState>();
		}
		case CardAction::PlusFour:
		{
			return SelectStateClassIndex<PlusFourCardsState>();
		}
		default: 
		{
			AssertNumberOfCardsStackedIsZero();
			return SelectStateClassIndex<DefaultTurnState>();
		}
	}
}

void RulesManager::AssertNumberOfCardsStackedIsZero()
{
	assert(numberOfCardsThatStacked == 0,
		"You can only have stacked cards on states that this is permitted.");
}

const std::vector<TurnAction> RulesManager::GetCurrentTurnActionsAvailable()
{
	return turnStates[currentStateClassIndex]->GetCurrentTurnActionsAvailable();
}

bool RulesManager::CanCardBePlayed(const Card& card)
{
	return turnStates[currentStateClassIndex]->CanCardBePlayed(card);
}

int RulesManager::GetNumberOfCardsToBeBought()
{
	return numberOfCardsThatStacked;
}


