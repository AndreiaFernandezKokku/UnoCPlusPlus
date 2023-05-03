#include "BuyCard.h"

std::optional<Card> BuyCard::TakeAction()
{
	if (numOfCardsToBeBought > 1)
	{
		Del->PlaceAmountOfDeckCardsInVector(CurrentCards, numOfCardsToBeBought);
	}
	else
	{
		Del->PlaceOneDeckCardInVector(CurrentCards);
	}
	return std::nullopt;
}
