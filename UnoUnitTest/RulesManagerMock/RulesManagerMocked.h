#pragma once
#include <vector>
#include "../../UnoCPlusPlus/RulesManager/IRulesForPlayerDataSource/IRulesForPlayerDataSource.h"

namespace UnoUnitTest
{
	class RulesManagerMocked : public IRulesForPlayerDataSource
	{
		bool IsCardInList(const Card& cardToSeach);
	public:
		std::vector<Card> CardsThatCanBePlayed;
		int NumberOfDeckCardsToBeBought;
		int NumberOfTableCardsToBeBought;

		RulesManagerMocked(std::vector<Card> cardsThatCanBePlayed,
			int numberOfDeckCardsToBeBought,
			int numberOfTableCardsToBeBought) :
			CardsThatCanBePlayed{ cardsThatCanBePlayed },
			NumberOfDeckCardsToBeBought{ numberOfDeckCardsToBeBought },
			NumberOfTableCardsToBeBought{ numberOfTableCardsToBeBought }
		{
		};

		bool CanCardBePlayed(const Card& card);

		int GetNumberOfDeckCardsToBeBought();

		int GetNumberOfTableCardsToBeBought();
	};
}