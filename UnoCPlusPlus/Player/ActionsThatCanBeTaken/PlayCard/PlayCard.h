#pragma once
#include "../IPlayerActionsThatCanBeTaken.h"

class PlayCard : public IPlayerActionsThatCanBeTaken
{
	std::vector<Card>& CurrentCards;
	const int CardIndexToPlay;

public:
	PlayCard(std::vector<Card>& currentCards, const int cardIndex) :
		IPlayerActionsThatCanBeTaken{ false },
		CurrentCards{ currentCards },
		CardIndexToPlay{ cardIndex }
	{};

	std::optional<Card> TakeAction() override;
};

