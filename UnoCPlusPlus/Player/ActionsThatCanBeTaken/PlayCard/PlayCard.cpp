#include "PlayCard.h"

std::optional<Card> PlayCard::TakeAction()
{
	Card cardToPlay = CurrentCards[cardIndexToPlay];
	CurrentCards.erase(CurrentCards.begin() + cardIndexToPlay);
	return cardToPlay;
}
