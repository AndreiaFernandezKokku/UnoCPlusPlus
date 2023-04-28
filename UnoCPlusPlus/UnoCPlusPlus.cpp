#include <iostream>
#include "TurnManager/TurnManager.h"

int main()
{
    TurnManager turnManager = TurnManager{};
    turnManager.SetupForFirstTurn();
    /*
    std::cout << "Hello World!\n";
    Importer importer = Importer{};
    std::vector<Card> AllCards = importer.GetAllCards();
    std::cout << "AllCardsCount " << AllCards.size() << std::endl;

    std::vector<Card> someCards = std::vector<Card>{};

    someCards.insert(someCards.end(), 
        std::make_move_iterator(AllCards.begin()),
        std::make_move_iterator(AllCards.begin() + 7));

    AllCards.erase(AllCards.begin(), AllCards.begin() + 7);

    std::cout << "AllCardsCount " << AllCards.size() << std::endl;
    std::cout << "someCards count " << someCards.size() << std::endl;
    printf("All cards 0 color %s and action %s\n", 
        ColorToString[static_cast<int>(AllCards[0].color)],
        CardActionToString[static_cast<int>(AllCards[0].action)]);

    printf("Some Cards cards 0 color %s and action %s\n",
    ColorToString[static_cast<int>(someCards[0].color)],
    CardActionToString[static_cast<int>(someCards[0].action)]);
    */
}

