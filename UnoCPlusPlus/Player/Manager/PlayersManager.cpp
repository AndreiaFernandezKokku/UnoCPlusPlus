#include "PlayersManager.h"
#include "../../Utilities/Header/RandomUtility.h"
#include "../../Utilities/Header/RandomNameGenerator.h"

void PlayersManager::PopulateAllPlayersVector()
{
	InputVariablesManager inputVariables = InputVariablesManager{};
	int numberOfPlayers = GetNumberOfPlayers(inputVariables);
	bool ShouldRandomize = static_cast<bool>(inputVariables.
		GetIntegerInput("Should I randomize the names? 0 for no, 1 for yes ", 0, 1));

	if (ShouldRandomize)
	{
		SetNamesRandomGenerator(numberOfPlayers);
	}
	else
	{
		SetNamesByInput(numberOfPlayers, inputVariables);
	}
}

int PlayersManager::GetNumberOfPlayers(InputVariablesManager inputVariables)
{
	return inputVariables.GetIntegerInput("Set the number of players ",
		MIN_NUM_OF_PLAYERS, MAX_NUM_OF_PLAYERS);
}

void PlayersManager::SetNamesByInput(int numberOfPlayers, InputVariablesManager inputVariables)
{
	for (int i = 0; i < numberOfPlayers; i++)
	{
		printf("Player %i ", i);
		std::shared_ptr<std::string> name = std::make_shared<std::string>(
			inputVariables.GetStringInput("set name", MIN_NUM_CHARACTERS_NAME,
			MAX_NUM_CHARACTERS_NAME));

		AllPlayers.push_back(Player(name));
	}
}

void PlayersManager::SetNamesRandomGenerator(int numberOfPlayers)
{
	for (int i = 0; i < numberOfPlayers; i++)
	{
		printf("Player %i ", i);
		RandomNameGenerator nameGenerator = RandomNameGenerator{};
		std::shared_ptr<std::string> name = std::make_shared<std::string>
			(nameGenerator.CompleteRandomName());

		printf("name is %s \n", name->c_str());
		AllPlayers.push_back(Player(name));
	}
}

void PlayersManager::ShuffleAllPlayersList()
{
	RandomUtility random = RandomUtility{};
	random.ShuffleVector<_vectorOfSharedPtrPlayer>
		(AllPlayers.begin(), AllPlayers.end());
}
