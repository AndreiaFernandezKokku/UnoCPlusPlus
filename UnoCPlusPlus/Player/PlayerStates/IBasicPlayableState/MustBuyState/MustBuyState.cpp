#include "MustBuyState.h"
#include "../../../ActionsThatCanBeTaken/PlayCard/PlayCard.h"
#include "../../../ActionsThatCanBeTaken/BuyCard/BuyCard.h"

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
		int numOfCardsToBuy = RulesDataSource->GetNumberOfDeckCardsToBeBought();
		printf("\n Buy %i cards from deck", numOfCardsToBuy);
		PrintActionNumber(PossibleActions.size());
		PossibleActions.emplace_back(
			std::make_unique<BuyCard>(CardsManagerDel, CurrentCards, numOfCardsToBuy));
	}

	return GetPlayerAction();
}

bool MustBuyState::CanPlayAnyCard()
{
	return PossibleActions.size() > 0;
}