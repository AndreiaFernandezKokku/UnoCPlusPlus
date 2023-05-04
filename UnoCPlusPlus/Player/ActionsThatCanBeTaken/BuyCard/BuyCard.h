#pragma once
#include "../IPlayerActionsThatCanBeTaken.h"
class BuyCard : public IPlayerActionsThatCanBeTaken
{
	ITurnManagerDelegate* Del;
	std::vector<Card>& CurrentCards;
	const int NumOfCardsToBeBought;

public:
	BuyCard(ITurnManagerDelegate* del, std::vector<Card>& currentCards, 
		const int numOfCardsToBuy) :
		IPlayerActionsThatCanBeTaken{ false },
		Del{ del },
		CurrentCards{ currentCards },
		NumOfCardsToBeBought{ numOfCardsToBuy }
	{};

	std::optional<Card> TakeAction() override;
};

