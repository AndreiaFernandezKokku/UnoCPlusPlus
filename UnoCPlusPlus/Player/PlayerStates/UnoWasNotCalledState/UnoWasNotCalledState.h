#pragma once
#include "../IPlayerState.h"
#include <vector>
#include "../../../Cards/ICardsManagerDelegate/ICardsManagerDelegate.h"

class UnoWasNotCalledState : public IPlayerState
{
public:
	std::shared_ptr<ICardsManagerDelegate> CardsManagerDel;
	std::shared_ptr<std::vector<Card>> CurrentCards;

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

