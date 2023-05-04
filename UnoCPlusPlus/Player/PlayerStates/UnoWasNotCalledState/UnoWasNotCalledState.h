#pragma once
#include "../IPlayerState.h"
#include <vector>
#include "../../../TurnManager/ITurnManagerDelegate/ITurnManagerDelegate.h"

class UnoWasNotCalledState : public IPlayerState
{
public:
	ITurnManagerDelegate* Del;
	std::vector<Card>& CurrentCards;

public:
	UnoWasNotCalledState(ITurnManagerDelegate* del,
	std::vector<Card>& currentCards) :
		Del{ del },
		CurrentCards{ currentCards }
	{};

	std::optional<Card> PlayTurn() override;
};

