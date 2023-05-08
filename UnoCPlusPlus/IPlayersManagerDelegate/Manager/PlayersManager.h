#pragma once
#include <vector>
#include <memory>
#include "../../Player/Player.h"
#include "../../Utilities/Header/InputVariablesManager.h"
#include "../IPlayersManagerDelegate.h"
#include "../../Utilities/Header/RandomNameGenerator.h"
#include "../../Cards/ICardsManagerDelegate/ICardsManagerDelegate.h"
#include "../../RulesManager/IRulesForPlayerDataSource/IRulesForPlayerDataSource.h"

class PlayersManager : public IPlayersManagerDelegate
{
private:
	const int MIN_NUM_OF_PLAYERS = 2;
	const int MAX_NUM_OF_PLAYERS = 10;
	const int MIN_NUM_CHARACTERS_NAME = 3;
	const int MAX_NUM_CHARACTERS_NAME = 10;

	std::vector<Player> AllPlayers;

	int GetNumberOfPlayers(InputVariablesManager inputVariables);
	bool ShouldRandomizeNames(InputVariablesManager inputVariables);
	std::shared_ptr<std::string> GetName(InputVariablesManager inputVariables);
	std::shared_ptr<std::string> GetRandomName(RandomNameGenerator* nameGenerator);
	void CreatePlayer(std::shared_ptr<std::string> name,
		std::shared_ptr<ICardsManagerDelegate> cardsManagerDel,
		std::shared_ptr<IRulesForPlayerDataSource> rulesDataSource);

public:
	void InitializePlayers(std::shared_ptr<ICardsManagerDelegate> cardsManagerDel,
		std::shared_ptr<IRulesForPlayerDataSource> rulesDataSource);
	void ShuffleAllPlayersList();
	void PrintInitialPlayers();

	std::vector<Player>& GetAllPlayers() override;
};

