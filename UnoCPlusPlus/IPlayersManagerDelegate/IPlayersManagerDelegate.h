#pragma once
#include <vector>
#include <memory>
#include "../Player/Player.h"

class IPlayersManagerDelegate
{
public:
	virtual std::vector<Player>& GetAllPlayers() = 0;
};