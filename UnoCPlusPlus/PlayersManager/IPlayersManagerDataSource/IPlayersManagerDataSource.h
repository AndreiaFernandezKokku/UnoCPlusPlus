#pragma once
#include <vector>
#include <memory>
#include "../../Player/Player.h"

class IPlayersManagerDataSource
{
public:
	virtual std::vector<Player>& GetAllPlayers() = 0;
};