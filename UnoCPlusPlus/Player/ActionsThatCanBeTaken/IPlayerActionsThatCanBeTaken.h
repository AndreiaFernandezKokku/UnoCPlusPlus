#pragma once
#include <optional>
#include <vector>
#include "../../Cards/Card.h"

class IPlayerActionsThatCanBeTaken
{
protected:
	IPlayerActionsThatCanBeTaken(bool isStackableAction) :
		IsStackableAction{ isStackableAction }
	{};


public:
	const bool IsStackableAction;
	virtual std::optional<Card> TakeAction() = 0;
};

