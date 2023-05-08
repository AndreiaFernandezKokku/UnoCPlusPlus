#include "MustBuyState.h"
#include "../../ActionsThatCanBeTaken/PlayCard/PlayCard.h"
#include "../../ActionsThatCanBeTaken/BuyCard/BuyCard.h"
#include "../../../Utilities/Header/InputVariablesManager.h"

std::optional<Card> MustBuyState::PlayTurn()
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
		int numOfCardsToBuy = RulesDataSource->GetNumberOfCardsToBeBought();
		printf("\n Buy %i cards", numOfCardsToBuy);
		PrintActionNumber(PossibleActions.size());
		PossibleActions.emplace_back(
			std::make_unique<BuyCard>(CardsManagerDel, CurrentCards, numOfCardsToBuy));
	}

	return PossibleActions[InputActionToTake()]->TakeAction();;
}

void MustBuyState::PrintCard(const Card & cardToPrint)
{
	printf("\n%s", Card::CardDataString(cardToPrint).c_str());
}

void MustBuyState::PrintActionNumber(int actionNumber)
{
	printf(" [%i] ", actionNumber);
}

bool MustBuyState::CanPlayAnyCard()
{
	return PossibleActions.size() > 0;
}

const int MustBuyState::InputActionToTake()
{
	InputVariablesManager inputManager = InputVariablesManager();
	const int index = inputManager.GetIntegerInput("\n Select action to take! ",
		0, PossibleActions.size() - 1);

	return index;
}
