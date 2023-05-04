#include "PlayCard.h"

std::optional<Card> PlayCard::TakeAction()
{
	Card cardToPlay = CurrentCards[CardIndexToPlay];
	CurrentCards.erase(CurrentCards.begin() + CardIndexToPlay);
	return cardToPlay;
}
