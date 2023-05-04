#pragma once
#include <optional>
#include <vector>
#include <memory>
#include "../../Cards/Card.h"
#include "../ActionsThatCanBeTaken/IPlayerActionsThatCanBeTaken.h"

class IPlayerState
{
protected:
	std::vector<std::unique_ptr<IPlayerActionsThatCanBeTaken>> PossibleActions;

public:
	virtual std::optional<Card> PlayTurn() = 0;
};