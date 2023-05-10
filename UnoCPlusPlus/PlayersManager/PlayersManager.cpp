#include "PlayersManager.h"


std::vector<Player>& PlayersManager::GetAllPlayers()
{
	return AllPlayers;
}

void PlayersManager::InitializePlayers(
	std::shared_ptr<ICardsManagerDelegate> cardsManagerDel, 
	std::shared_ptr<IRulesForPlayerDataSource> rulesDataSource)
{
	int numberOfPlayers = GetNumberOfPlayers();
	bool randomNames = ShouldRandomizeNames();

	RandomNameGenerator nameGenerator = RandomNameGenerator{random};

	for (int i = 0; i < numberOfPlayers; i++)
	{
		printf("Player %i ", i);
		std::shared_ptr<std::string> name;
		if (randomNames)
		{
			name = GetRandomName(&nameGenerator);
			printf("name is %s \n", name->c_str());
		}
		else
		{
			name = GetName();
			printf("\n");
		}
		CreatePlayer(name, cardsManagerDel, rulesDataSource);
	}
	ShuffleAllPlayersList();
}

int PlayersManager::GetNumberOfPlayers()
{
	return inputVariables.GetIntegerInput("Set the number of players ",
		MIN_NUM_OF_PLAYERS, MAX_NUM_OF_PLAYERS);
}

bool PlayersManager::ShouldRandomizeNames()
{
	return static_cast<bool>(inputVariables.
	GetIntegerInput("Should I randomize the names? 0 for no, 1 for yes ", 0, 1));
}

std::shared_ptr<std::string> PlayersManager::GetName()
{
	return std::make_shared<std::string>(
			inputVariables.GetStringInput("Set player name", MIN_NUM_CHARACTERS_NAME,
		MAX_NUM_CHARACTERS_NAME));
}

std::shared_ptr<std::string> PlayersManager::GetRandomName(
	RandomNameGenerator* nameGenerator)
{
	return std::make_shared<std::string>(nameGenerator->CompleteRandomName());
}

void PlayersManager::CreatePlayer(std::shared_ptr<std::string> name, 
	std::shared_ptr<ICardsManagerDelegate> cardsManagerDel, 
	std::shared_ptr<IRulesForPlayerDataSource> rulesDataSource)
{
	AllPlayers.push_back(Player(name, cardsManagerDel, rulesDataSource, inputVariables));
}

void PlayersManager::ShuffleAllPlayersList()
{
	random.ShuffleVector<std::vector<Player>>(AllPlayers.begin(), AllPlayers.end());
}

void PlayersManager::PrintInitialPlayers()
{
	printf("Players in play order \n");
	for (Player& player : AllPlayers)
	{
		player.PrintCurrentCards();
	}
}
