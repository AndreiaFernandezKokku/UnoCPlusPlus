#pragma once
#include "../IBasicPlayableState.h"
#include "../../../../Cards/ICardsManagerDelegate/ICardsManagerDelegate.h"
#include "../../../../RulesManager/IRulesForPlayerDataSource/IRulesForPlayerDataSource.h"

class MustBuyFromTableState : public IBasicPlayableState
{
private:
	std::shared_ptr<ICardsManagerDelegate> CardsManagerDel;
	std::shared_ptr<IRulesForPlayerDataSource> RulesDataSource;

	std::shared_ptr<std::vector<Card>> CurrentCards;

	bool CanPlayAnyCard();

public:
	MustBuyFromTableState(std::shared_ptr<ICardsManagerDelegate> cardsManagerDel,
		std::shared_ptr<IRulesForPlayerDataSource> rulesDataSource,
		std::shared_ptr<std::vector<Card>> currentCards,
		IInputVariables& inputManager) :
		CardsManagerDel{ cardsManagerDel },
		RulesDataSource{ rulesDataSource },
		CurrentCards{ currentCards },
		IBasicPlayableState{ inputManager }
	{};

	std::optional<Card> PlayTurn() override;

	//Stopping wrong delete
	~MustBuyFromTableState() = default;
};

