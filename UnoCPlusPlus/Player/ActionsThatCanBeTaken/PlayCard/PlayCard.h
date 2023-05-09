#pragma once
#include "../IPlayerActionsThatCanBeTaken.h"
#include <memory>

class PlayCard : public IPlayerActionsThatCanBeTaken
{
	std::shared_ptr<std::vector<Card>> CurrentCards;
	const int CardIndexToPlay;

public:
	PlayCard(std::shared_ptr<std::vector<Card>>  currentCards, const int cardIndex) :
		IPlayerActionsThatCanBeTaken{ false },
		CurrentCards{ currentCards },
		CardIndexToPlay{ cardIndex }
	{};

	std::optional<Card> TakeAction() override;

	//Stopping wrong delete
	~PlayCard() = default;
};

