#pragma once
#include <vector>
#include <memory>
#include <optional>
#include "../RulesManager/IRulesForPlayerDataSource/IRulesForPlayerDataSource.h"
#include "../Cards/ICardsManagerDelegate/ICardsManagerDelegate.h"
#include "../Cards/Card.h"
#include "../RulesManager/TurnAction/TurnAction.h"
#include "../Utilities/IInputVariables.h"
#include "PlayerStates/IPlayerState.h"
#include "PlayerStates/DefaultState/DefaultState.h"
#include "PlayerStates/GotJumpedState/GotJumpedState.h"
#include "PlayerStates/MustBuyState/MustBuyState.h"
#include "PlayerStates/UnoWasNotCalledState/UnoWasNotCalledState.h"
#include "PlayerStates/MustBuyFromTableState/MustBuyFromTableState.h"

class Player
{
private:
	std::shared_ptr<std::vector<Card>> sharedPtrCurrentCards;
	std::shared_ptr<std::string> name;
	std::vector<std::unique_ptr<IPlayerState>> possibleStates;
	std::shared_ptr<bool> unoWasCalledOutPtr;

	void InitializeVariables(std::shared_ptr<ICardsManagerDelegate> cardsManagerDel);
	void InitializeStates(std::shared_ptr<ICardsManagerDelegate> cardsManagerDel,
		std::shared_ptr<IRulesForPlayerDataSource> rulesDataSource,
		IInputVariables& inputUtil);

	std::unique_ptr<IPlayerState>& SelectState(std::vector<TurnAction> turnAction);
	bool GotJumped(std::vector<TurnAction> turnAction);
	bool ShouldBuyMultipleCard(std::vector<TurnAction> turnAction);
	bool ShouldBuyMultipleCardFromTable(std::vector<TurnAction> turnAction);

	template<typename stateClass>
	std::unique_ptr<IPlayerState>& SelectStateClass()
	{
		for (auto& state : possibleStates)
		{
			if (dynamic_cast<stateClass*>(state.get()))
			{
				return state;
			}
		}
	}

public:
	Player(std::shared_ptr<std::string> nam, 
		std::shared_ptr<ICardsManagerDelegate> cardsManager, 
		std::shared_ptr<IRulesForPlayerDataSource> rulesDataSource,
		IInputVariables& inputUtil) :
		name{ nam }
	{
		InitializeVariables(cardsManager);
		InitializeStates(cardsManager, rulesDataSource, inputUtil);
	};


	std::optional<Card> StartTurn(std::vector<TurnAction> turnAction);
	const char* GetName();
	const int GetCurrentCardsSize();
	void PrintCurrentCards();
};