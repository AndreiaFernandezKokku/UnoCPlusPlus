#pragma once
#include <vector>
#include <memory>
#include "../IBasicPlayableState.h"
#include "../../../../RulesManager/IRulesForPlayerDataSource/IRulesForPlayerDataSource.h"
#include "../../../../Cards/ICardsManagerDelegate/ICardsManagerDelegate.h"

class DefaultState : public IBasicPlayableState
{
private:
	std::shared_ptr<ICardsManagerDelegate> CardsManagerDel;
	std::shared_ptr<IRulesForPlayerDataSource> RulesDataSource;

	std::shared_ptr<std::vector<Card>> CurrentCards;
	std::shared_ptr<bool> HasCalledUno;

	void PopulatePossibleActions();
	bool CanPlayAnyCard();

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
		IBasicPlayableState{ inputManager }
	{};

	std::optional<Card> PlayTurn() override;

	//Stopping wrong delete
	~DefaultState() = default;
};

