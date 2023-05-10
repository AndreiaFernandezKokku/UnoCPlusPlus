#include "pch.h"
#include "CppUnitTest.h"
#include "../UnoCPlusPlus/Cards/Importer/Importer.h"
#include "../UnoCPlusPlus/Cards/ICardsManagerDelegate/Manager/CardsManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnoUnitTest
{
	TEST_CLASS(ImporterTest)
	{
	public:
		
		TEST_METHOD(TestImporter)
		{
			int expectedNumberOfCards = 112;
			Importer cardImporter = Importer{};
			int actualNumberOfCards = 
				static_cast<int>(cardImporter.GetAllCards().size());
			Assert::AreEqual(expectedNumberOfCards, actualNumberOfCards);
		}
	};
}
