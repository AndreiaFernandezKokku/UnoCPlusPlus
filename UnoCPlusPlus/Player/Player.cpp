#include "Player.h"
#include "ActionsThatCanBeTaken/BuyCard/BuyCard.h"
#include "ActionsThatCanBeTaken/PlayCard/PlayCard.h"
#include "../Utilities/Header/InputVariablesManager.h"

std::optional<Card> Player::StartTurn(std::vector<TurnAction> turnAction)
{
    possibleActions.clear();
    printf("\nIt's %s turn!", GetName());
    if (!CanPlay(turnAction))
    {
        printf("\nOh no you got a negation, oh noes... You can't play. \n");
        return std::nullopt;
    }

    ShowPlaceCardAction();
    if (ShouldBuyMultipleCard(turnAction))
    {
        ShowObligationToBuyCard();
    }
    else
    {
        ShowBuyCardIfNoOwnedCardsIsValid();
    }

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

void Player::ShowPlaceCardAction()
{
    for (int i = 0; i < currentCards.size(); i++)
    {
        PrintCard(currentCards[i]);
        if (!del->CanCardBePlayed(currentCards[i])) continue;
        PrintAction(possibleActions.size());
        possibleActions.emplace_back(
            std::make_unique<PlayCard>(del, currentCards, i));
    }
}

void Player::ShowObligationToBuyCard()
{
    const int numOfCardsToBuy = del->NumberOfCardsToBeBought();
    printf("\n Buy %i cards", numOfCardsToBuy);
    PrintAction(possibleActions.size());
    possibleActions.emplace_back(
        std::make_unique<BuyCard>(del, currentCards, numOfCardsToBuy));
}

void Player::ShowBuyCardIfNoOwnedCardsIsValid()
{
    if (possibleActions.size() > 0) return;
    printf("\n Buy %i cards", 1);
    PrintAction(possibleActions.size());
    possibleActions.emplace_back(
        std::make_unique<BuyCard>(del, currentCards, 1));
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
