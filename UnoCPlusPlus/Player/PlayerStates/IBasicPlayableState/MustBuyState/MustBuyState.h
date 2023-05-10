#pragma once
#include "../IBasicPlayableState.h"
#include "../../../../RulesManager/IRulesForPlayerDataSource/IRulesForPlayerDataSource.h"
#include "../../../../Cards/ICardsManagerDelegate/ICardsManagerDelegate.h"

class MustBuyState : public IBasicPlayableState
{
private:
	std::shared_ptr<ICardsManagerDelegate> CardsManagerDel;
	std::shared_ptr<IRulesForPlayerDataSource> RulesDataSource;

	std::shared_ptr<std::vector<Card>> CurrentCards;

	bool CanPlayAnyCard();

public:
	MustBuyState(std::shared_ptr<ICardsManagerDelegate> cardsManagerDel,
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
	~MustBuyState() = default;
};

