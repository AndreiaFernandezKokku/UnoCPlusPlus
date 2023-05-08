#include "BuyCard.h"

std::optional<Card> BuyCard::TakeAction()
{
	if (NumOfCardsToBeBought > 1)
	{
		CardsManagerDel->
			PlaceAmountOfCardsFromDeckInVector(
				std::move(*CurrentCards), NumOfCardsToBeBought);
	}
	else
	{
		CardsManagerDel->PlaceOneCardFromDeckInVector(std::move(*CurrentCards));
	}
	return std::nullopt;
}
