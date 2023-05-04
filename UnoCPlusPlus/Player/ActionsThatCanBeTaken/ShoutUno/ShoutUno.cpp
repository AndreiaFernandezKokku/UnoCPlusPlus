#include "ShoutUno.h"

std::optional<Card> ShoutUno::TakeAction()
{
	printf("\n UNOO!! \n");
	*UnoCallOut = true;
	return std::optional<Card>();
}
