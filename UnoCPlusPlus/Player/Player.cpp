#include "Player.h"
#include "ActionsThatCanBeTaken/BuyCard/BuyCard.h"
#include "ActionsThatCanBeTaken/PlayCard/PlayCard.h"
#include "../Utilities/Header/InputVariablesManager.h"

std::optional<Card> Player::StartTurn(std::vector<TurnAction> turnAction)
{
    possibleActions.clear();
    printf("It's %s turn! \n", GetName());
    if (!CanPlay(turnAction))
    {
        printf("Oh no you got a negation, oh noes... You can't play. \n");
        return std::nullopt;
    }

    ShowAvailableActions(turnAction);

    return possibleActions[SelectActionToTake()]->TakeAction();
}

bool Player::CanPlay(std::vector<TurnAction> turnAction)
{
    if (std::find(turnAction.begin(), turnAction.end(),
        TurnAction::Jumped) != turnAction.end())
    {
        return false;
    }
    return true;
}

void Player::ShowAvailableActions(std::vector<TurnAction> turnAction)
{
    int actionNumber = 0;
    if (CanPlayCard(turnAction))
    {
        for (int i = 0; i < currentCards.size(); i++)
        {
            PrintCard(currentCards[i]);
            if (!del->CanCardBePlayed(currentCards[i])) continue;
            PrintAction(actionNumber);
            possibleActions.emplace_back(
                std::make_unique<PlayCard>(del, currentCards, i));
            actionNumber++;
        }
    }

    if (ShouldBuyMultipleCard(turnAction))
    {
        const int numOfCardsToBuy = del->NumberOfCardsToBeBought();
        printf("\n Buy %i cards", numOfCardsToBuy);
        PrintAction(actionNumber);
        possibleActions.emplace_back(
            std::make_unique<BuyCard>(del, currentCards, numOfCardsToBuy));
    }
    else
    {
        printf("\n Buy %i cards", 1);
        PrintAction(actionNumber);
        possibleActions.emplace_back(
            std::make_unique<BuyCard>(del, currentCards, 1));
    }
}

bool Player::CanPlayCard(std::vector<TurnAction> turnAction)
{
    if (std::find(turnAction.begin(), turnAction.end(),
        TurnAction::CanPlayCard) != turnAction.end())
    {
        return true;
    }
    return false;
}

bool Player::ShouldBuyMultipleCard(std::vector<TurnAction> turnAction)
{
    if (std::find(turnAction.begin(), turnAction.end(),
        TurnAction::BuyMultipleCard) != turnAction.end())
    {
        return true;
    }
    return false;
}

void Player::PrintAction(int actionNumber)
{
    printf(" [%i] ", actionNumber);
}

void Player::PrintCard(const Card& cardToPrint)
{
    printf("\n| %s , %s |",
        ColorToString[static_cast<int>(cardToPrint.color)],
        CardActionToString[static_cast<int>(cardToPrint.action)]);
}

const int Player::SelectActionToTake()
{
    InputVariablesManager inputManager = InputVariablesManager();
    const int index = inputManager.GetIntegerInput("\n Select action to take! ", 
        0, possibleActions.size() - 1);

    return index;
}

const char* Player::GetName()
{
    return name->c_str();
}

std::vector<Card>& Player::GetCurrentCards()
{
    return currentCards;
}

const int Player::GetCurrentCardsSize()
{
    return currentCards.size();
}

void Player::PrintCurrentCards()
{
    printf("Player %s cards are: \n", GetName());
    for (const Card card : currentCards)
    {
        printf("| %s , %s | \n",
            ColorToString[static_cast<int>(card.color)],
            CardActionToString[static_cast<int>(card.action)]);
    }
}
