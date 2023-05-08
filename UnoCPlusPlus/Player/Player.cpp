#include "Player.h"
#include <cassert>

void Player::InitializeStates(std::shared_ptr<ICardsManagerDelegate> cardsManagerDel,
        std::shared_ptr<IRulesForPlayerDataSource> rulesDataSource)
{
    sharedPtrCurrentCards = std::make_shared<std::vector<Card>>();
    unoWasCalledOutPtr = std::make_shared<bool>(false);
    cardsManagerDel->PlaceInitialCardsInVector(std::move(*sharedPtrCurrentCards));

    possibleStates.emplace_back(
        std::make_unique<DefaultState>(cardsManagerDel, 
        rulesDataSource, sharedPtrCurrentCards, unoWasCalledOutPtr));

    possibleStates.emplace_back(
        std::make_unique<GotJumpedState>());

    possibleStates.emplace_back(
        std::make_unique<MustBuyState>(cardsManagerDel,
        rulesDataSource, sharedPtrCurrentCards));

    possibleStates.emplace_back(
        std::make_unique<UnoWasNotCalledState>(cardsManagerDel, sharedPtrCurrentCards));
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
        *unoWasCalledOutPtr = false;
        currentState = 2;
        return;
    }
    if (sharedPtrCurrentCards->size() == 1 && *unoWasCalledOutPtr == false)
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

const int Player::GetCurrentCardsSize()
{
    return sharedPtrCurrentCards->size();
}

void Player::PrintCurrentCards()
{
    printf("Player %s cards are: \n", GetName());
    for (const Card card : *sharedPtrCurrentCards)
    {
        printf("| %s , %s | \n",
            ColorToString[static_cast<int>(card.color)],
            CardActionToString[static_cast<int>(card.action)]);
    }
}
