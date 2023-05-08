#pragma once
#include "../../Cards/Card.h"

class IRulesForPlayerDataSource
{
public:
	virtual bool CanCardBePlayed(const Card& card) = 0;
	virtual int GetNumberOfCardsToBeBought() = 0;
};