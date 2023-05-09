#include "Player.h"
#include <cassert>


void Player::InitializeVariables(std::shared_ptr<ICardsManagerDelegate> cardsManagerDel)
{
    sharedPtrCurrentCards = std::make_shared<std::vector<Card>>();
    unoWasCalledOutPtr = std::make_shared<bool>(false);

    cardsManagerDel->PlaceInitialCardsInVector(*sharedPtrCurrentCards);
}

void Player::InitializeStates(std::shared_ptr<ICardsManagerDelegate> cardsManagerDel,
        std::shared_ptr<IRulesForPlayerDataSource> rulesDataSource)
{
    possibleStates.emplace_back(
        std::make_unique<DefaultState>(cardsManagerDel, 
        rulesDataSource, sharedPtrCurrentCards, unoWasCalledOutPtr));

    possibleStates.emplace_back(std::make_unique<GotJumpedState>());

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
    std::unique_ptr<IPlayerState>& stateSelected = SelectState(turnAction);
    return stateSelected->PlayTurn();
}

std::unique_ptr<IPlayerState>& Player::SelectState(std::vector<TurnAction> turnAction)
{
    if (GotJumped(turnAction))
    {
        return SelectStateClass<GotJumpedState>();
    }
    if (ShouldBuyMultipleCard(turnAction))
    {
        *unoWasCalledOutPtr = false;
        return SelectStateClass<MustBuyState>();
    }
    if (sharedPtrCurrentCards->size() == 1 && *unoWasCalledOutPtr == false)
    {
        return SelectStateClass<UnoWasNotCalledState>();
    }
    return SelectStateClass<DefaultState>();
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
        printf("%s\n", Card::CardDataString(card).c_str());
    }
}
