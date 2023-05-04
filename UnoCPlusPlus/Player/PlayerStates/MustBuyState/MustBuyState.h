#pragma once
#include <vector>
#include <memory>
#include "../IPlayerState.h"
#include "../../../TurnManager/ITurnManagerDelegate/ITurnManagerDelegate.h"
#include "../../ActionsThatCanBeTaken/IPlayerActionsThatCanBeTaken.h"

class MustBuyState : public IPlayerState
{
private:
	ITurnManagerDelegate* Del;
	std::vector<Card>& CurrentCards;

	void PrintCard(const Card& cardToPrint);
	void PrintActionNumber(int actionNumber);
	bool CanPlayAnyCard();
	const int InputActionToTake();

public:
	MustBuyState(ITurnManagerDelegate* del,
		std::vector<Card>& currentCards) :
		Del{ del },
		CurrentCards{ currentCards }
	{};

	std::optional<Card> PlayTurn() override;
};

