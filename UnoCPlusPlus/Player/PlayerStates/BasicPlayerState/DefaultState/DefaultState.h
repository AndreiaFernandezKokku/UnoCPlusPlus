#pragma once
#include <vector>
#include <memory>
#include "../../IPlayerState.h"
#include "../../../ActionsThatCanBeTaken/IPlayerActionsThatCanBeTaken.h"
#include "../../../../RulesManager/IRulesForPlayerDataSource/IRulesForPlayerDataSource.h"
#include "../../../../Cards/ICardsManagerDelegate/ICardsManagerDelegate.h"
#include "../../../../Utilities/IInputVariables.h"

class DefaultState : public IPlayerState
{
private:
	std::shared_ptr<ICardsManagerDelegate> CardsManagerDel;
	std::shared_ptr<IRulesForPlayerDataSource> RulesDataSource;

	std::shared_ptr<std::vector<Card>> CurrentCards;
	std::shared_ptr<bool> HasCalledUno;

	IInputVariables& InputManager;

	void PopulatePossibleActions();
	void PrintCard(const Card& cardToPrint);
	void PrintActionNumber(int actionNumber);
	bool CanPlayAnyCard();
	std::optional<Card> GetPlayerAction();
	const int InputActionToTake();

public:
	DefaultState(std::shared_ptr<ICardsManagerDelegate> cardsManagerDel,
		std::shared_ptr<IRulesForPlayerDataSource> rulesDataSource,
		std::shared_ptr<std::vector<Card>> currentCards,
		std::shared_ptr<bool> hasCalledUno,
		IInputVariables& inputManager) :
		CardsManagerDel{ cardsManagerDel },
		RulesDataSource{ rulesDataSource },
		CurrentCards{ currentCards },
		HasCalledUno{ hasCalledUno },
		InputManager{ inputManager }
	{};

	std::optional<Card> PlayTurn() override;

	//Stopping wrong delete
	~DefaultState() = default;
};

