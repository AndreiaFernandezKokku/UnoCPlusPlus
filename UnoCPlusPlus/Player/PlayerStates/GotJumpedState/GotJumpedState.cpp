#include "GotJumpedState.h"

std::optional<Card> GotJumpedState::PlayTurn()
{
	PossibleActions.clear();
	printf("\nOh no, you got jumped, oh noes... You can't play. \n");
	return std::nullopt;
}
