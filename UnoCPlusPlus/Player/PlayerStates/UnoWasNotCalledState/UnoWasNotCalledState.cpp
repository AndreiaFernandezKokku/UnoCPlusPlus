#include "UnoWasNotCalledState.h"
#include "../../ActionsThatCanBeTaken/BuyCard/BuyCard.h"

std::optional<Card> UnoWasNotCalledState::PlayTurn()
{
	printf("\nUh oh, you didn't call uno!");
	printf("\n You buy 2 cards");
	return BuyCard(Del, CurrentCards, 2).TakeAction();
}
