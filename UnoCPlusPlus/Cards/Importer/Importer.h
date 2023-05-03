#pragma once
#include <vector>
#include "../Card.h"

class Importer
{
	//todo
	//Temporary implementation.
	//Final implementation should open a file and read it.
public:
	std::vector<Card> GetAllCards();
};