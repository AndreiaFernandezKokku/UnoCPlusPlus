#include "UnoWasNotCalledState.h"
#include "../../ActionsThatCanBeTaken/BuyCard/BuyCard.h"

std::optional<Card> UnoWasNotCalledState::PlayTurn()
{
	PossibleActions.clear();
	printf("\nUh oh, you didn't call uno!\n You buy 2 cards from deck\n");
	return BuyCard(CardsManagerDel, CurrentCards, NUMBER_OF_CARDS_TO_BUY).TakeAction();
}
