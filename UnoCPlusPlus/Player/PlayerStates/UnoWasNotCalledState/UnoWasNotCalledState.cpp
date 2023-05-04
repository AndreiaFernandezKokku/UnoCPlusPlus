#include "UnoWasNotCalledState.h"
#include "../../ActionsThatCanBeTaken/BuyCard/BuyCard.h"

std::optional<Card> UnoWasNotCalledState::PlayTurn()
{
	PossibleActions.clear();
	printf("\nUh oh, you didn't call uno!\n You buy 2 cards \n");
	return BuyCard(Del, CurrentCards, 2).TakeAction();
}
