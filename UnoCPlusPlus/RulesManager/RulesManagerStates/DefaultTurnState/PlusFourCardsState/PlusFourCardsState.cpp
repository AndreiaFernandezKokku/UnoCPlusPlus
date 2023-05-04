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
	for (int i = 0; i < sizeof(Color); i++)
	{
		printf("%s [%i] \n",
			ColorToString[static_cast<int>(Color(i))], i);
	}
	int input = manager.GetIntegerInput("", 0, sizeof(Color) - 1);
	return Color(input);
}