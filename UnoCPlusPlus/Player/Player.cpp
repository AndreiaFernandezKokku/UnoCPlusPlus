#include "Player.h"
#include <cassert>

void Player::InitializeStates(ITurnManagerDelegate* deleg)
{
    possibleStates.emplace_back(
        std::make_unique<DefaultState>(deleg, currentCards, &unoWasCalledOut));
    possibleStates.emplace_back(
        std::make_unique<GotJumpedState>());
    possibleStates.emplace_back(
        std::make_unique<MustBuyState>(deleg, currentCards));
    possibleStates.emplace_back(
        std::make_unique<UnoWasNotCalledState>(deleg, currentCards));
}

std::optional<Card> Player::StartTurn(std::vector<TurnAction> turnAction)
{
    assert(possibleStates.size() > 0,
        "Before starting the turns, you need to initialize the player states");
    printf("\nIt's %s turn!", GetName());
    SelectState(turnAction);
    return possibleStates[currentState]->PlayTurn();
}

void Player::SelectState(std::vector<TurnAction> turnAction)
{
    if (GotJumped(turnAction))
    {
        currentState = 1;
        return;
    }
    if (ShouldBuyMultipleCard(turnAction))
    {
        unoWasCalledOut = false;
        currentState = 2;
        return;
    }
    if (currentCards.size() == 1 && unoWasCalledOut == false)
    {
        currentState = 3;
        return;
    }
    currentState = 0;
}

bool Player::GotJumped(std::vector<TurnAction> turnAction)
{
    if (std::find(turnAction.begin(), turnAction.end(),
        TurnAction::Jumped) != turnAction.end())
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
