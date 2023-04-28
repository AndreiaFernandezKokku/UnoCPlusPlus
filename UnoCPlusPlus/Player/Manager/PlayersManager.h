#pragma once
#include <vector>
#include <memory>
#include "../Player.h"

class PlayersManager
{
	using _sharedPtrPlayer = std::shared_ptr<Player>;
	using _vectorOfSharedPtrPlayer = std::vector<Player>;
private:
	const int MIN_NUM_OF_PLAYERS = 2;
	const int MAX_NUM_OF_PLAYERS = 10;
	const int MIN_NUM_CHARACTERS_NAME = 3;
	const int MAX_NUM_CHARACTERS_NAME = 10;

public:
	_vectorOfSharedPtrPlayer AllPlayers;

	void PopulateAllPlayersVector();
	void ShuffleAllPlayersList();
};

