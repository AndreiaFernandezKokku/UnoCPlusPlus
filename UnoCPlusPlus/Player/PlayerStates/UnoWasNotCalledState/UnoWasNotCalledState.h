#pragma once
#include "../IPlayerState.h"
#include "../../../Cards/ICardsManagerDelegate/ICardsManagerDelegate.h"

class UnoWasNotCalledState : public IPlayerState
{
private:
	std::shared_ptr<ICardsManagerDelegate> CardsManagerDel;
	std::shared_ptr<std::vector<Card>> CurrentCards;
	const int NUMBER_OF_CARDS_TO_BUY = 2;

public:
	UnoWasNotCalledState(std::shared_ptr<ICardsManagerDelegate> cardsManagerDel,
	std::shared_ptr<std::vector<Card>> currentCards) :
		CardsManagerDel{ cardsManagerDel },
		CurrentCards{ currentCards }
	{};

	std::optional<Card> PlayTurn() override;

	//Stopping wrong delete
	~UnoWasNotCalledState() = default;
};

