#include "MustBuyFromTableState.h"
#include "../../../ActionsThatCanBeTaken/PlayCard/PlayCard.h"
#include "../../../../Utilities/IInputVariables.h"
#include "../../../ActionsThatCanBeTaken/BuyFromTableCard/BuyFromTableCard.h"

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

	return GetPlayerAction();
}

bool MustBuyFromTableState::CanPlayAnyCard()
{
	return PossibleActions.size() > 0;
}


