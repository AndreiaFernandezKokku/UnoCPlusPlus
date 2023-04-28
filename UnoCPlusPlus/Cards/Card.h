#pragma once
#include <Color.h>
#include <CardAction.h>

struct Card
{
	Color color;
	CardAction action;

	Card(Color col, CardAction act) :
		color{ col }, action{ act }
	{};
};