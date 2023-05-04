#include "BuyCard.h"

std::optional<Card> BuyCard::TakeAction()
{
	if (NumOfCardsToBeBought > 1)
	{
		Del->PlaceAmountOfDeckCardsInVector(CurrentCards, NumOfCardsToBeBought);
	}
	else
	{
		Del->PlaceOneDeckCardInVector(CurrentCards);
	}
	return std::nullopt;
}
