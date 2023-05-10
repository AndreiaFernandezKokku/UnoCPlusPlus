#include "IBasicPlayableState.h"

void IBasicPlayableState::PrintCard(const Card& cardToPrint)
{
	printf("\n%s", Card::CardDataString(cardToPrint).c_str());
}

void IBasicPlayableState::PrintActionNumber(int actionNumber)
{
	printf(" [%i] ", actionNumber);
}

std::optional<Card> IBasicPlayableState::GetPlayerAction()
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

const int IBasicPlayableState::InputActionToTake()
{
	const int index = InputManager.GetIntegerInput("\n Select action to take! ",
		0, PossibleActions.size() - 1);

	return index;
}
