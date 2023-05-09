#pragma once
#include "../IPlayerActionsThatCanBeTaken.h"
#include <memory>
#include "../../../Cards/ICardsManagerDelegate/ICardsManagerDelegate.h"

class BuyCard : public IPlayerActionsThatCanBeTaken
{
private:
	std::shared_ptr<ICardsManagerDelegate> CardsManagerDel;
	std::shared_ptr<std::vector<Card>> CurrentCards;
	const int NumOfCardsToBeBought;

public:
	BuyCard(std::shared_ptr<ICardsManagerDelegate> cardsManagerDel, 
		std::shared_ptr<std::vector<Card>> currentCards,
		const int numOfCardsToBuy) :
		IPlayerActionsThatCanBeTaken{ false },
		CardsManagerDel{ cardsManagerDel },
		CurrentCards{ currentCards },
		NumOfCardsToBeBought{ numOfCardsToBuy }
	{};

	std::optional<Card> TakeAction() override;

	//Stopping wrong delete
	~BuyCard() = default;
};

