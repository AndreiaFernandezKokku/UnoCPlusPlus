#pragma once
#include "../IPlayerActionsThatCanBeTaken.h"

class ShoutUno : public IPlayerActionsThatCanBeTaken
{
	bool* UnoCallOut;

public:
	ShoutUno(bool* unoWasCalledOut) :
		IPlayerActionsThatCanBeTaken{ true },
		UnoCallOut{ unoWasCalledOut }
	{};

	std::optional<Card> TakeAction() override;
};

