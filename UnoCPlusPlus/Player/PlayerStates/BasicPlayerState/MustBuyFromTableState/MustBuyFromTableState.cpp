#include "MustBuyFromTableState.h"
#include "../../ActionsThatCanBeTaken/PlayCard/PlayCard.h"
#include "../../../Utilities/IInputVariables.h"
#include "../../ActionsThatCanBeTaken/BuyFromTableCard/BuyFromTableCard.h"

std::optional<Card> MustBuyFromTableState::PlayTurn()
{
	PossibleActions.clear();

	for (int i = 0; i < CurrentCards->size(); i++)
	{
		PrintCard(CurrentCards->at(i));
		if (!RulesDataSource->CanCardBePlayed(CurrentCards->at(i))) continue;
		PrintActionNumber(PossibleActions.size());
		PossibleActions.emplace_back(
			std::make_unique<PlayCard>(CurrentCards, i));
	}
	if (!CanPlayAnyCard())
	{
		int numOfCardsToBuy = RulesDataSource->GetNumberOfTableCardsToBeBought();
		printf("\n Buy %i cards from table", numOfCardsToBuy);
		PrintActionNumber(PossibleActions.size());
		PossibleActions.emplace_back(
			std::make_unique<BuyFromTableCard>(CardsManagerDel, 
			CurrentCards, numOfCardsToBuy));
	}

	return PossibleActions[InputActionToTake()]->TakeAction();;
}

void MustBuyFromTableState::PrintCard(const Card& cardToPrint)
{
	printf("\n%s", Card::CardDataString(cardToPrint).c_str());
}

void MustBuyFromTableState::PrintActionNumber(int actionNumber)
{
	printf(" [%i] ", actionNumber);
}

bool MustBuyFromTableState::CanPlayAnyCard()
{
	return PossibleActions.size() > 0;
}

const int MustBuyFromTableState::InputActionToTake()
{
	InputVariablesManager inputManager = InputVariablesManager();
	const int index = inputManager.GetIntegerInput("\n Select action to take! ",
		0, PossibleActions.size() - 1);

	return index;
}


