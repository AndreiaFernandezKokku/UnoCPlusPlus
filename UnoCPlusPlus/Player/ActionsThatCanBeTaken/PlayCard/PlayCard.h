#pragma once
#include "../IPlayerActionsThatCanBeTaken.h"

class PlayCard : public IPlayerActionsThatCanBeTaken
{
	const int cardIndexToPlay;
public:
	PlayCard(ITurnManagerDelegate* del,
		std::vector<Card>& currentCards, const int cardIndex) :
		IPlayerActionsThatCanBeTaken{ del, currentCards }, cardIndexToPlay{ cardIndex }
	{};

	std::optional<Card> TakeAction() override;
};

