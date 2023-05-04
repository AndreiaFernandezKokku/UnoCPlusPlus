#include "MustBuyState.h"
#include "../../ActionsThatCanBeTaken/PlayCard/PlayCard.h"
#include "../../ActionsThatCanBeTaken/BuyCard/BuyCard.h"
#include "../../../Utilities/Header/InputVariablesManager.h"

std::optional<Card> MustBuyState::PlayTurn()
{
	PossibleActions.clear();

	for (int i = 0; i < CurrentCards.size(); i++)
	{
		PrintCard(CurrentCards[i]);
		if (!Del->CanCardBePlayed(CurrentCards[i])) continue;
		PrintActionNumber(PossibleActions.size());
		PossibleActions.emplace_back(
			std::make_unique<PlayCard>(CurrentCards, i));
	}
	if (!CanPlayAnyCard())
	{
		int numOfCardsToBuy = Del->NumberOfCardsToBeBought();
		printf("\n Buy %i cards", numOfCardsToBuy);
		PrintActionNumber(PossibleActions.size());
		PossibleActions.emplace_back(
			std::make_unique<BuyCard>(Del, CurrentCards, numOfCardsToBuy));
	}

	return PossibleActions[InputActionToTake()]->TakeAction();;
}

void MustBuyState::PrintCard(const Card & cardToPrint)
{
	printf("\n| %s , %s |",
		ColorToString[static_cast<int>(cardToPrint.color)],
		CardActionToString[static_cast<int>(cardToPrint.action)]);
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
