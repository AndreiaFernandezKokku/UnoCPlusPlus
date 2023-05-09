#pragma once
#include "../IPlayerActionsThatCanBeTaken.h"
#include "../../../Cards/ICardsManagerDelegate/ICardsManagerDelegate.h"

class BuyFromTableCard : public IPlayerActionsThatCanBeTaken
{
private:
	std::shared_ptr<ICardsManagerDelegate> CardsManagerDel;
	std::shared_ptr<std::vector<Card>> CurrentCards;
	const int NumOfCardsToBeBought;

public:
	BuyFromTableCard(std::shared_ptr<ICardsManagerDelegate> cardsManagerDel,
		std::shared_ptr<std::vector<Card>> currentCards,
		const int numOfCardsToBuy) :
		IPlayerActionsThatCanBeTaken{ false },
		CardsManagerDel{ cardsManagerDel },
		CurrentCards{ currentCards },
		NumOfCardsToBeBought{ numOfCardsToBuy }
	{};

	std::optional<Card> TakeAction() override;

	//Stopping wrong delete
	~BuyFromTableCard() = default;
};

