#pragma once
#include "../IPlayerState.h"

class GotJumpedState : public IPlayerState
{
public:
	std::optional<Card> PlayTurn() override;

	//Stopping wrong delete
	~GotJumpedState() = default;
};

