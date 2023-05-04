#pragma once
#include "../IRulesState.h"
#include "../../TurnAction/TurnAction.h"
#include "../../../Cards/Card.h"

class DefaultTurnState : public IRulesState
{
protected:
	std::vector<Color> ColorsThatCanBePlayed;
	std::vector<CardAction> CardActThatCanBePlayed;
	std::vector<TurnAction> ActionsToTake;

	bool HasPlayableColor(const Color& color);
	bool HasPlayableAction(const CardAction& action);
	void UpdateCurrentColorThatCanBePlayed(const Color& color);
	void AddAllColors();
	void UpdateCurrentActionThatCanBePlayed(const CardAction& action);
	void ClearAllCurrentVariables();

public: 
	std::vector<TurnAction> GetCurrentTurnActionsAvailable() override;
	void NewCardOnTable(Card currentTableCard) override;
	void NoNewCardOnTable() override;
	bool CanCardBePlayed(const Card& card) override;
};