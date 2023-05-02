#pragma once
#include <vector>
#include <memory>
#include "../Cards/Card.h"
#include <optional>

class Player
{
private:
	std::vector<Card> currentCards;
	std::shared_ptr<std::string> name;
public:

	Player(std::shared_ptr<std::string> nam) :
		name{ nam }
	{};
	std::optional<Card> StartTurn();
	const char* GetName();
	std::vector<Card>& GetCurrentCards();
	const int GetCurrentCardsSize();
	void PrintCurrentCards();
};