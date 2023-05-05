#include "PlusFourCardsState.h"
#include "../../../../Utilities/Header/InputVariablesManager.h"

void PlusFourCardsState::NewCardOnTable(Card currentTableCard)
{
	ClearAllCurrentVariables();

	CurrentColor = SelectColor();
	CardActThatCanBePlayed.push_back(currentTableCard.action);
	ActionsToTake.push_back(TurnAction::BuyMultipleCard);
	*NumberOfStackedCards += 4;
}

void PlusFourCardsState::NoNewCardOnTable()
{
	ActionsToTake.clear();
	*NumberOfStackedCards = 0;
	UpdateCurrentColorThatCanBePlayed(CurrentColor);
	printf("Color picked was %s\n", ColorToString[static_cast<int>(CurrentColor)]);
}

Color PlusFourCardsState::SelectColor()
{
	InputVariablesManager manager = InputVariablesManager();
	printf("Select next card color \n");

	//Since Count = last, and any = last -1, we need the last color
	//so -2
	int lastColor = static_cast<int>(Color::Count) - 2;

	for (int i = 0; i <= lastColor; i++)
	{
		printf("%s [%i] \n", ColorToString[i], i);
	}
	int input = manager.GetIntegerInput("", 0, lastColor);
	
	return Color(input);
}