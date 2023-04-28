#include "PlayersManager.h"
#include "../../Utilities/Header/InputVariablesManager.h"3
#include "../../Utilities/Header/RandomUtility.h"

void PlayersManager::PopulateAllPlayersVector()
{
	InputVariablesManager inputVariables = InputVariablesManager{};
	int numberOfPlayers = 
		inputVariables.GetIntegerInput("Set the number of players ", 
			MIN_NUM_OF_PLAYERS, MAX_NUM_OF_PLAYERS);

	for (int i = 0; i < numberOfPlayers; i++)
	{
		printf("Player %i ", i);
		std::shared_ptr<std::string> name = std::make_shared<std::string>(
			inputVariables.GetStringInput("set name", MIN_NUM_CHARACTERS_NAME, 
			MAX_NUM_CHARACTERS_NAME));

		AllPlayers.push_back(Player(name));
	}
}

void PlayersManager::ShuffleAllPlayersList()
{
	RandomUtility random = RandomUtility{};
	random.ShuffleVector<_vectorOfSharedPtrPlayer>
		(AllPlayers.begin(), AllPlayers.end());
}
