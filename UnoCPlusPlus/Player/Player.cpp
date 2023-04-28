#include "Player.h"

void Player::StartTurn()
{
}

const char* Player::GetName()
{
    return name->c_str();
}

std::vector<Card>& Player::GetCurrentCards()
{
    return currentCards;
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