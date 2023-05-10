#include "DefaultState.h"
#include "../../../ActionsThatCanBeTaken/PlayCard/PlayCard.h"
#include "../../../ActionsThatCanBeTaken/ShoutUno/ShoutUno.h"
#include "../../../ActionsThatCanBeTaken/BuyCard/BuyCard.h"

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
		printf("\n Buy 1 card from deck");
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

bool DefaultState::CanPlayAnyCard()
{
	return PossibleActions.size() > 0;
}
