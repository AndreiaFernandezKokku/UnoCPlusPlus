#include "pch.h"
#include "CppUnitTest.h"
#include "../UnoCPlusPlus/Cards/Importer/Importer.h"
#include "../UnoCPlusPlus/Cards/ICardsManagerDelegate/Manager/CardsManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnoUnitTest
{
	TEST_CLASS(CardsManagerTest)
	{
		CardsManager cm = CardsManager{};
	public:
		TEST_METHOD(InitialCardsToPlaceInVector)
		{
			std::vector<Card> cardVectorToTest;
			cm.Initialize();
			int expectedNumberOfInitialCards = 7;

			cm.PlaceInitialCardsInVector(cardVectorToTest);
			Assert::AreEqual(
				static_cast<int>(cardVectorToTest.size()), expectedNumberOfInitialCards);
		}
	};
}