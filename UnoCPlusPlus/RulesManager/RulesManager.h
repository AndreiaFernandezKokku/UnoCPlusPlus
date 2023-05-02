#pragma once
#include <iostream>
#include <vector>
#include <optional>
#include "../Cards/Card.h"
#include "TurnAction/TurnAction.h"

class RulesManager
{
	//todo add uno rules
private:
	std::vector<Color> colorsThatCanBePlayed;
	std::vector<CardAction> cardActThatCanBePlayed;
	int numberOfCardsThatStacked;
	std::vector<TurnAction> actionsToTake;

	void UpdateActionsBasedOnCardActions(const Card& currentTableCard);
	void UpdateCurrentCardsThatCanBePlayed(const Card& currentTableCard);
	void AddAllColors();
	void AddAllActionsAndColors();
	bool HasPlayableColor(const Color& color);
	bool HasPlayableAction(const CardAction& action);
public:
	//todo separate for turn manager actions
	void NewCardOnTable(std::optional<Card> currentTableCard);
	void NoNewCardOnTable();
	//todo serparate for player actions
	const std::vector<TurnAction> GetCurrentTurnActionsAvailable();
	bool CanCardBePlayed(const Card& card);
	int GetNumberOfCardsToBeBought();
};

