#pragma once
#include "../../Cards/Card.h"

class IRulesForPlayerDataSource
{
public:
	virtual bool CanCardBePlayed(const Card& card) = 0;
	virtual int GetNumberOfDeckCardsToBeBought() = 0;
	virtual int GetNumberOfTableCardsToBeBought() = 0;
};