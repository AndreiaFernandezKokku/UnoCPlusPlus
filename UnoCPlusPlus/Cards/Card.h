#pragma once
#include "Color.h"
#include "CardAction.h"
#include <format>

struct Card
{
public:
	Color color;
	CardAction action;

	Card(Color col, CardAction act) :
		color{ col }, action{ act }
	{
	};

	static std::string CardDataString(const Card& card)
	{
		return std::format("| {} , {} |",
			ColorToString[static_cast<int>(card.color)],
			CardActionToString[static_cast<int>(card.action)]);
	}
};