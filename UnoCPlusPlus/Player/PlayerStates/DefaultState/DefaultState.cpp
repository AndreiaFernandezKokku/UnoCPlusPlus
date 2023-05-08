#include "DefaultState.h"
#include "../../ActionsThatCanBeTaken/PlayCard/PlayCard.h"
#include "../../ActionsThatCanBeTaken/ShoutUno/ShoutUno.h"
#include "../../ActionsThatCanBeTaken/BuyCard/BuyCard.h"
#include "../../../Utilities/Header/InputVariablesManager.h"

std::optional<Card> DefaultState::PlayTurn()
{
	PopulatePossibleActions();

	return GetPlayerAction();
}

void DefaultState::PopulatePossibleActions()
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
		*HasCalledUno = false;
		printf("\n Buy 1 card");
		PrintActionNumber(PossibleActions.size());
		PossibleActions.emplace_back(
			std::make_unique<BuyCard>(CardsManagerDel, CurrentCards, 1));
	}
	else if (CurrentCards->size() == 2)
	{
		printf("\n Shout uno");
		PrintActionNumber(PossibleActions.size());
		PossibleActions.emplace_back(
			std::make_unique<ShoutUno>(HasCalledUno));
	}
}

void DefaultState::PrintCard(const Card& cardToPrint)
{
	printf("\n| %s , %s |",
		ColorToString[static_cast<int>(cardToPrint.color)],
		CardActionToString[static_cast<int>(cardToPrint.action)]);
}

void DefaultState::PrintActionNumber(int actionNumber)
{
	printf(" [%i] ", actionNumber);
}

bool DefaultState::CanPlayAnyCard()
{
	return PossibleActions.size() > 0;
}

std::optional<Card> DefaultState::GetPlayerAction()
{
	bool stackableAction = true;
	std::optional<Card> cardToReturn = std::nullopt;
	while (stackableAction)
	{
		int selection = InputActionToTake();
		stackableAction = PossibleActions[selection]->IsStackableAction;
		cardToReturn = PossibleActions[selection]->TakeAction();
	}
	return cardToReturn;
}

const int DefaultState::InputActionToTake()
{
	InputVariablesManager inputManager = InputVariablesManager();
	const int index = inputManager.GetIntegerInput("\n Select action to take! ",
		0, PossibleActions.size() - 1);

	return index;
}
