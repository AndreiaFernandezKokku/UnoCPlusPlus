#pragma once
#include "../IPlayerActionsThatCanBeTaken.h"
#include <memory>

class ShoutUno : public IPlayerActionsThatCanBeTaken
{
	std::shared_ptr<bool> UnoCallOut;

public:
	ShoutUno(std::shared_ptr<bool> unoWasCalledOut) :
		IPlayerActionsThatCanBeTaken{ true },
		UnoCallOut{ unoWasCalledOut }
	{};

	std::optional<Card> TakeAction() override;

	//Stopping wrong delete
	~ShoutUno() = default;
};

