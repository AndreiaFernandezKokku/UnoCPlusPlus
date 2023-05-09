#include "RulesManager.h"
#include <cassert>


RulesManager::RulesManager()
{
	turnStates.emplace_back(std::make_unique<FirstTurnState>());
	turnStates.emplace_back(std::make_unique<DefaultTurnState>());
	turnStates.emplace_back(std::make_unique<JumpTurnState>());
	turnStates.emplace_back(std::make_unique<ReverseTurnState>());
	turnStates.emplace_back(
		std::make_unique<PlusTwoCardsState>(&numberOfDeckCardsThatStacked));
	turnStates.emplace_back(
		std::make_unique<PlusFourCardsState>(&numberOfDeckCardsThatStacked));
	turnStates.emplace_back(
		std::make_unique<PlusTwoDiscardState>(&numberOfTableCardsThatStacked));
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
			AssertNumberOfDeckCardsStackedIsZero();
			AssertNumberOfTableCardsStackedIsZero();
			return SelectStateClassIndex<ReverseTurnState>();
		}
		case CardAction::Jump:
		{
			AssertNumberOfDeckCardsStackedIsZero();
			AssertNumberOfTableCardsStackedIsZero();
			return SelectStateClassIndex<JumpTurnState>();
		}
		case CardAction::PlusTwo:
		{
			AssertNumberOfTableCardsStackedIsZero();
			return SelectStateClassIndex<PlusTwoCardsState>();
		}
		case CardAction::PlusFour:
		{
			AssertNumberOfTableCardsStackedIsZero();
			return SelectStateClassIndex<PlusFourCardsState>();
		}
		case CardAction::PlusTwoDiscard:
		{
			AssertNumberOfDeckCardsStackedIsZero();
			return SelectStateClassIndex<PlusTwoDiscardState>();
		}
		default: 
		{
			AssertNumberOfTableCardsStackedIsZero();
			AssertNumberOfDeckCardsStackedIsZero();
			return SelectStateClassIndex<DefaultTurnState>();
		}
	}
}

void RulesManager::AssertNumberOfDeckCardsStackedIsZero()
{
	assert(numberOfDeckCardsThatStacked == 0,
		"You can only have deck stacked cards on states that this is permitted.");
}

void RulesManager::AssertNumberOfTableCardsStackedIsZero()
{
	assert(numberOfTableCardsThatStacked == 0,
		"You can only have table cards stacked on stated that this is permitted.");
}

const std::vector<TurnAction> RulesManager::GetCurrentTurnActionsAvailable()
{
	return turnStates[currentStateClassIndex]->GetCurrentTurnActionsAvailable();
}

bool RulesManager::CanCardBePlayed(const Card& card)
{
	return turnStates[currentStateClassIndex]->CanCardBePlayed(card);
}

int RulesManager::GetNumberOfDeckCardsToBeBought()
{
	return numberOfDeckCardsThatStacked;
}

int RulesManager::GetNumberOfTableCardsToBeBought()
{
	return numberOfTableCardsThatStacked;
}


