#pragma once
#include <vector>
#include <memory>
#include "../IPlayerState.h"
#include "../../../TurnManager/ITurnManagerDelegate/ITurnManagerDelegate.h"
#include "../../ActionsThatCanBeTaken/IPlayerActionsThatCanBeTaken.h"

class DefaultState : public IPlayerState
{
private:
	ITurnManagerDelegate* Del;
	std::vector<Card>& CurrentCards;
	bool* HasCalledUno;

	void PopulatePossibleActions();
	void PrintCard(const Card& cardToPrint);
	void PrintActionNumber(int actionNumber);
	bool CanPlayAnyCard();
	std::optional<Card> GetPlayerAction();
	const int InputActionToTake();

public:
	DefaultState(ITurnManagerDelegate* del, 
		std::vector<Card>& currentCards,
		bool* hasCalledUno) :
		Del{ del },
		CurrentCards{ currentCards },
		HasCalledUno{ hasCalledUno }
	{};

	std::optional<Card> PlayTurn() override;
};

