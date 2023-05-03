#pragma once
#include "../IPlayerActionsThatCanBeTaken.h"
class BuyCard : public IPlayerActionsThatCanBeTaken
{
	const int numOfCardsToBeBought;

public:
	BuyCard(ITurnManagerDelegate* del, std::vector<Card>& currentCards, 
		const int numOfCardsToBuy) :
		IPlayerActionsThatCanBeTaken{ del, currentCards }, 
		numOfCardsToBeBought{ numOfCardsToBuy }
	{};

	std::optional<Card> TakeAction() override;
};

