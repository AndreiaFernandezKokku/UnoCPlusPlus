#pragma once
#include <vector>
#include <memory>
#include "../Cards/Card.h"

class Player
{
private:
	std::vector<Card> currentCards;
	std::shared_ptr<std::string> name;
public:

	Player(std::shared_ptr<std::string> nam) :
		name{ nam }
	{};
	void StartTurn();
	const char* GetName();
	std::vector<Card>& GetCurrentCards();
	void PrintCurrentCards();
};