#pragma once
#include <iostream>
#include <vector>
#include <optional>
#include "../Cards/Card.h"
#include "TurnAction/TurnAction.h"

class RulesManager
{
private:
	std::vector<Color> colorsThatCanBePlayed;
	std::vector<CardAction> cardActThatCanBePlayed;
	int numberOfCardsThatStacked;
	bool wasCardEvaluated; //needed?
	std::vector<TurnAction> actionsToTake;

	void UpdateActionsBasedOnCardActions(const Card& currentTableCard);
	void UpdateCurrentCardsThatCanBePlayed(const Card& currentTableCard);
	void AddAllColors();
	void AddAllActionsAndColors();
	bool HasPlayableColor(const Card& card);
	bool HasPlayableAction(const Card& card);
public:
	void UpdateValidActions(std::optional<Card> currentTableCard);
	bool CanCardBePlayed(const Card& card);
};

