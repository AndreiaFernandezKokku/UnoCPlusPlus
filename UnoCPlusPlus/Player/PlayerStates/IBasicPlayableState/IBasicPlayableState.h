#pragma once
#include "../IPlayerState.h"
#include "../../../Utilities/IInputVariables.h"

class IBasicPlayableState : public IPlayerState
{
private:
	IInputVariables& InputManager;

protected:
	void PrintCard(const Card& cardToPrint);
	void PrintActionNumber(int actionNumber);
	std::optional<Card> GetPlayerAction();
	const int InputActionToTake();

public:
	IBasicPlayableState(IInputVariables& inputManager) : InputManager{ inputManager } {};
	
	//Stopping wrong delete
	virtual ~IBasicPlayableState() = default;

	virtual std::optional<Card> PlayTurn() = 0;
};

