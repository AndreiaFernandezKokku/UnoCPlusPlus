#pragma once
#include "../../UnoCPlusPlus/Cards/ICardsManagerDelegate/ICardsManagerDelegate.h"

namespace UnoUnitTest
{
	class CardsManagerMocked : public ICardsManagerDelegate
	{
	public:
		std::vector<Card> InitialCards;
		std::vector<Card> Deck;
		std::vector<Card> Table;

		CardsManagerMocked(std::vector<Card> initialCards,
			std::vector<Card> deck,
			std::vector<Card> table) :
			InitialCards{ initialCards },
			Deck{ deck },
			Table{ table }
		{
		};

		void PlaceInitialCardsInVector(std::vector<Card>& vectorToPlace);

		void PlaceOneCardFromDeckInVector(std::vector<Card>& vectorToPlace);

		void PlaceAmountOfCardsFromDeckInVector(std::vector<Card>& vectorToPlace,
			int amount);

		void PlaceAmountOfCardsFromTableInVector(std::vector<Card>& vectorToPlace,
			int amount);

		const std::optional<Card> GetLastCardFromTable();

		void PlaceCardOnTable(Card cardToPlaceOnTable);

		int PrintDeckAmountOfCards();

		int PrintTableAmountOfCards();
	};
}