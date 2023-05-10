#pragma once
#include <vector>
#include <memory>
#include "IPlayersManagerDataSource/IPlayersManagerDataSource.h"
#include "../Utilities/IInputVariables.h"
#include "../Utilities/ConcreteClasses/Header/RandomUtility.h"
#include "../Utilities/ConcreteClasses/Header/RandomNameGenerator.h"
#include "../Cards/ICardsManagerDelegate/ICardsManagerDelegate.h"
#include "../RulesManager/IRulesForPlayerDataSource/IRulesForPlayerDataSource.h"

class PlayersManager : public IPlayersManagerDataSource
{
private:
	const int MIN_NUM_OF_PLAYERS = 2;
	const int MAX_NUM_OF_PLAYERS = 10;
	const int MIN_NUM_CHARACTERS_NAME = 3;
	const int MAX_NUM_CHARACTERS_NAME = 10;

	std::vector<Player> AllPlayers;
	IInputVariables& inputVariables;
	RandomUtility& random;

	int GetNumberOfPlayers();
	bool ShouldRandomizeNames();
	std::shared_ptr<std::string> GetName();
	std::shared_ptr<std::string> GetRandomName(RandomNameGenerator* nameGenerator);
	void CreatePlayer(std::shared_ptr<std::string> name,
		std::shared_ptr<ICardsManagerDelegate> cardsManagerDel,
		std::shared_ptr<IRulesForPlayerDataSource> rulesDataSource);

public:
	PlayersManager(IInputVariables& inputUtil, RandomUtility& randomUtil) : 
		inputVariables{ inputUtil }, random{ randomUtil }
	{};

	void InitializePlayers(std::shared_ptr<ICardsManagerDelegate> cardsManagerDel,
		std::shared_ptr<IRulesForPlayerDataSource> rulesDataSource);
	void ShuffleAllPlayersList();
	void PrintInitialPlayers();

	std::vector<Player>& GetAllPlayers() override;
};

