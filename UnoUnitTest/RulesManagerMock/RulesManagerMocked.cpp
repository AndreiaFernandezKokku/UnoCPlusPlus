#include "RulesManagerMocked.h"

bool UnoUnitTest::RulesManagerMocked::IsCardInList(const Card& cardToSeach)
{
	if (std::find(CardsThatCanBePlayed.begin(), CardsThatCanBePlayed.end(),
		cardToSeach) != CardsThatCanBePlayed.end())
	{
		return true;
	}
	return false;
}

bool UnoUnitTest::RulesManagerMocked::CanCardBePlayed(const Card& card)
{
	return IsCardInList(card);
}

int UnoUnitTest::RulesManagerMocked::GetNumberOfDeckCardsToBeBought()
{
	return NumberOfDeckCardsToBeBought;
}

int UnoUnitTest::RulesManagerMocked::GetNumberOfTableCardsToBeBought()
{
	return NumberOfTableCardsToBeBought;
}
