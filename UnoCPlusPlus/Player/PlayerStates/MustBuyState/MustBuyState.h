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
	//These possible actions would only be cleaned when we access this state again :(
	std::vector<std::unique_ptr<IPlayerActionsThatCanBeTaken>> PossibleActions;

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

