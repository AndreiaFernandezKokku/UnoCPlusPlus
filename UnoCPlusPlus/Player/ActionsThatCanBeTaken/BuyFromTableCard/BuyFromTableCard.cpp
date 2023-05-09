#include "BuyFromTableCard.h"
#include <cassert>

std::optional<Card> BuyFromTableCard::TakeAction()
{
	assert(NumOfCardsToBeBought > 0,
		"It makes no sense to buy 0 table cards.");
	CardsManagerDel->PlaceAmountOfCardsFromTableInVector(
			*CurrentCards, NumOfCardsToBeBought);
	return std::nullopt;
}
