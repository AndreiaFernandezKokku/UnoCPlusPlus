#pragma once
#include "../IPlayerState.h"
#include "../../../Cards/ICardsManagerDelegate/ICardsManagerDelegate.h"
#include "../../../RulesManager/IRulesForPlayerDataSource/IRulesForPlayerDataSource.h"

class MustBuyFromTableState : public IPlayerState
{
private:
	std::shared_ptr<ICardsManagerDelegate> CardsManagerDel;
	std::shared_ptr<IRulesForPlayerDataSource> RulesDataSource;

	std::shared_ptr<std::vector<Card>> CurrentCards;

	void PrintCard(const Card& cardToPrint);
	void PrintActionNumber(int actionNumber);
	bool CanPlayAnyCard();
	const int InputActionToTake();

public:
	MustBuyFromTableState(std::shared_ptr<ICardsManagerDelegate> cardsManagerDel,
		std::shared_ptr<IRulesForPlayerDataSource> rulesDataSource,
		std::shared_ptr<std::vector<Card>> currentCards) :
		CardsManagerDel{ cardsManagerDel },
		RulesDataSource{ rulesDataSource },
		CurrentCards{ currentCards }
	{
	};

	std::optional<Card> PlayTurn() override;

	//Stopping wrong delete
	~MustBuyFromTableState() = default;
};

