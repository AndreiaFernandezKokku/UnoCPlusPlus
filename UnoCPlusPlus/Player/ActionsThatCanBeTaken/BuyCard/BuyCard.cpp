#include "BuyCard.h"

std::optional<Card> BuyCard::TakeAction()
{
	if (NumOfCardsToBeBought > 1)
	{
		CardsManagerDel->
			PlaceAmountOfCardsFromDeckInVector(
				*CurrentCards, NumOfCardsToBeBought);
	}
	else
	{
		CardsManagerDel->PlaceOneCardFromDeckInVector(*CurrentCards);
	}
	return std::nullopt;
}
