#include "pch.h"
#include "CppUnitTest.h"
#include "../UnoCPlusPlus/Cards/Importer/Importer.h"
#include "../UnoCPlusPlus/Cards/ICardsManagerDelegate/Manager/CardsManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnoUnitTest
{
	TEST_CLASS(CardsManagerTest)
	{
		//todo, test random
		CardsManager cm = CardsManager{};
		int totalNumberOfCards = Importer{}.GetAllCards().size();

	public:
		TEST_METHOD(Initialization)
		{
			cm.Initialize();

			Assert::AreEqual(totalNumberOfCards, cm.PrintDeckAmountOfCards());
		}

		TEST_METHOD(CardPlacementFromDeck)
		{
			std::vector<Card> cardVectorToTest;
			cm.Initialize();

			InitialCardPlacement(cardVectorToTest);

			PlaceOneCard(cardVectorToTest);

			PlaceMultipleCards(cardVectorToTest);
		}

		TEST_METHOD(CardPlacementInTable)
		{
			cm.Initialize();

			WhenInitializedTableShouldBeEmpty();

			PlaceCardFromIntermediateVectorInTable();
		}

		TEST_METHOD(CardPlacementFromTable)
		{

		}

		TEST_METHOD(SendCardsFromTableToDeck)
		{

		}

		void InitialCardPlacement(std::vector<Card>& cardVectorToTest)
		{
			cm.PlaceInitialCardsInVector(cardVectorToTest);

			Assert::AreEqual(
				cm.INITIAL_CARDS, static_cast<int>(cardVectorToTest.size()));

			Assert::AreEqual(totalNumberOfCards - cm.INITIAL_CARDS,
				cm.PrintDeckAmountOfCards());
		}

		void PlaceOneCard(std::vector<Card>& cardVectorToTest)
		{
			int expectedCardVectorSize = cardVectorToTest.size() + 1;
			int expectedDeckAmountOfCards = 
				totalNumberOfCards - expectedCardVectorSize;

			cm.PlaceOneCardFromDeckInVector(cardVectorToTest);

			Assert::AreEqual(expectedCardVectorSize, 
				static_cast<int>(cardVectorToTest.size()));
			Assert::AreEqual(expectedDeckAmountOfCards, cm.PrintDeckAmountOfCards());
		}

		void PlaceMultipleCards(std::vector<Card>& cardVectorToTest)
		{
			int cardAmountToInsert = 5;
			int expectedCardVectorSize = cardVectorToTest.size() + cardAmountToInsert;
			int expectedDeckAmountOfCards =
				totalNumberOfCards - expectedCardVectorSize;

			cm.PlaceAmountOfCardsFromDeckInVector(cardVectorToTest, cardAmountToInsert);

			Assert::AreEqual(expectedCardVectorSize,
				static_cast<int>(cardVectorToTest.size()));
			Assert::AreEqual(expectedDeckAmountOfCards, cm.PrintDeckAmountOfCards());
		}

		void WhenInitializedTableShouldBeEmpty()
		{
			Assert::AreEqual(false, cm.GetLastCardFromTable().has_value());
		}

		void PlaceCardFromIntermediateVectorInTable()
		{
			std::vector<Card> intermediateCardVector;

			cm.PlaceOneCardFromDeckInVector(intermediateCardVector);
			Card expectedCard = intermediateCardVector.back();
			cm.PlaceCardOnTable(intermediateCardVector.back());

			Assert::AreEqual(1, cm.PrintTableAmountOfCards());

			Card actualCard = cm.GetLastCardFromTable().value();

			Assert::AreEqual(Card::CardDataString(expectedCard),
				Card::CardDataString(actualCard));
		}
	};
}