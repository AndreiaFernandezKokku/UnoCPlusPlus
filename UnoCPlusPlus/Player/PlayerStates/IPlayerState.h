#pragma once
#include <optional>
#include "../../Cards/Card.h"

class IPlayerState
{
public:
	virtual std::optional<Card> PlayTurn() = 0;
};