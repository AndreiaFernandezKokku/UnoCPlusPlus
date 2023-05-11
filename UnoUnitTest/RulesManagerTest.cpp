#include "pch.h"
#include "CppUnitTest.h"
#include "../UnoCPlusPlus/RulesManager/RulesManager.h"
#include "InputVariablesManagerMock/InputVariablesManagerMocked.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnoUnitTest
{
	TEST_CLASS(RulesManagerTest)
	{
		// Red on enum == 2
		InputVariablesManagerMocked fakeInput = InputVariablesManagerMocked{2};
		RulesManager rm = RulesManager{ fakeInput };
	public:
		TEST_METHOD(CommonCardBehaviour)
		{
			Card blueZero = Card(Color::Blue, CardAction::Zero);
			Card cannotBePlayed = Card(Color::Red, CardAction::One);
			Card sameColor = Card(Color::Blue, CardAction::One);
			Card sameAction = Card(Color::Yellow, CardAction::Zero);
			Card anyColor = Card(Color::Any, CardAction::PlusFour);

			rm.NewCardOnTable(blueZero);

			TurnActionsShouldBeZero();
			CardsStackShouldBeZero();
			CommonCardTest(cannotBePlayed, sameColor, sameAction, anyColor);
			
			rm.NoNewCardOnTable();

			TurnActionsShouldBeZero();
			CardsStackShouldBeZero();
			CommonCardTest(cannotBePlayed, sameColor, sameAction, anyColor);
		}

		TEST_METHOD(PlusTwoCardBehaviour)
		{
			Card redPlusTwo = Card(Color::Red, CardAction::PlusTwo);
			Card cannotBePlayed = Card(Color::Yellow, CardAction::One);
			Card sameColor = Card(Color::Red, CardAction::One);
			Card sameAction = Card(Color::Yellow, CardAction::PlusTwo);
			Card plusFour = Card(Color::Blue, CardAction::PlusFour);
			Card anyColor = Card(Color::Any, CardAction::Two);

			rm.NewCardOnTable(redPlusTwo);

			TurnActionShouldContain(TurnAction::BuyMultipleCard);
			Assert::AreEqual(2, static_cast<int>(rm.GetNumberOfDeckCardsToBeBought()));
			Assert::AreEqual(0, static_cast<int>(rm.GetNumberOfTableCardsToBeBought()));

			SpecialCardPlacedOnTable(cannotBePlayed, sameColor, sameAction, anyColor);
			Assert::IsTrue(rm.CanCardBePlayed(plusFour));

			rm.NoNewCardOnTable();

			TurnActionsShouldBeZero();
			CardsStackShouldBeZero();
			CommonCardTest(cannotBePlayed, sameColor, sameAction, anyColor);
		}

		TEST_METHOD(ReverseCardBehaviour)
		{
			Card redReverse = Card(Color::Red, CardAction::Reverse);
			Card cannotBePlayed = Card(Color::Yellow, CardAction::One);
			Card sameColor = Card(Color::Red, CardAction::One);
			Card sameAction = Card(Color::Yellow, CardAction::Reverse);
			Card anyColor = Card(Color::Any, CardAction::Two);

			rm.NewCardOnTable(redReverse);

			TurnActionShouldContain(TurnAction::Reverse);
			CardsStackShouldBeZero();
			CommonCardTest(cannotBePlayed, sameColor, sameAction, anyColor);
		}

		TEST_METHOD(JumpCardBehaviour)
		{
			Card redJump = Card(Color::Red, CardAction::Jump);
			Card cannotBePlayed = Card(Color::Yellow, CardAction::One);
			Card sameColor = Card(Color::Red, CardAction::One);
			Card sameAction = Card(Color::Yellow, CardAction::Jump);
			Card anyColor = Card(Color::Any, CardAction::Two);

			rm.NewCardOnTable(redJump);

			TurnActionShouldContain(TurnAction::Jumped);
			CardsStackShouldBeZero();
			CommonCardTest(cannotBePlayed, sameColor, sameAction, anyColor);
		}

		TEST_METHOD(PlusTwoFromTableCardBehaviour)
		{
			Card redPlusTwoDiscard = Card(Color::Red, CardAction::PlusTwoDiscard);
			Card cannotBePlayed = Card(Color::Yellow, CardAction::One);
			Card sameColor = Card(Color::Red, CardAction::One);
			Card sameAction = Card(Color::Yellow, CardAction::PlusTwoDiscard);
			Card plusFour = Card(Color::Blue, CardAction::PlusFour);
			Card anyColor = Card(Color::Any, CardAction::Two);

			rm.NewCardOnTable(redPlusTwoDiscard);

			TurnActionShouldContain(TurnAction::BuyMultipleTableCard);
			Assert::AreEqual(0, static_cast<int>(rm.GetNumberOfDeckCardsToBeBought()));
			Assert::AreEqual(2, static_cast<int>(rm.GetNumberOfTableCardsToBeBought()));

			SpecialCardPlacedOnTable(cannotBePlayed, sameColor, sameAction, anyColor);
			Assert::IsFalse(rm.CanCardBePlayed(plusFour));

			rm.NoNewCardOnTable();

			TurnActionsShouldBeZero();
			CardsStackShouldBeZero();
			CommonCardTest(cannotBePlayed, sameColor, sameAction, anyColor);
		}

		TEST_METHOD(PlusFourCardBehaviour)
		{
			Card anyPlusFourCard = Card(Color::Any, CardAction::PlusFour);
			Card cannotBePlayed = Card(Color::Yellow, CardAction::One);
			Card pickedColor = Card(Color::Red, CardAction::One);
			Card sameAction = Card(Color::Yellow, CardAction::PlusFour);
			Card plusTwo = Card(Color::Blue, CardAction::PlusTwo);
			Card anyColor = Card(Color::Any, CardAction::Two);

			rm.NewCardOnTable(anyPlusFourCard);

			TurnActionShouldContain(TurnAction::BuyMultipleCard);
			Assert::AreEqual(4, static_cast<int>(rm.GetNumberOfDeckCardsToBeBought()));
			Assert::AreEqual(0, static_cast<int>(rm.GetNumberOfTableCardsToBeBought()));

			SpecialCardPlacedOnTable(cannotBePlayed, pickedColor, sameAction, anyColor);
			Assert::IsFalse(rm.CanCardBePlayed(plusTwo));

			rm.NoNewCardOnTable();

			TurnActionsShouldBeZero();
			CardsStackShouldBeZero();
			CommonCardTest(cannotBePlayed, pickedColor, sameAction, anyColor);
		}

		void TurnActionsShouldBeZero()
		{
			std::vector<TurnAction> turnAction = rm.GetCurrentTurnActionsAvailable();

			Assert::AreEqual(0, static_cast<int>(turnAction.size()));
		}

		void CardsStackShouldBeZero()
		{
			Assert::AreEqual(0, static_cast<int>(rm.GetNumberOfDeckCardsToBeBought()));
			Assert::AreEqual(0, static_cast<int>(rm.GetNumberOfTableCardsToBeBought()));
		}

		void CommonCardTest(Card cannotBePlayed, Card sameColor,
			Card sameAction, Card anyColor)
		{
			Assert::IsTrue(rm.CanCardBePlayed(sameColor));
			Assert::IsTrue(rm.CanCardBePlayed(sameAction));
			Assert::IsTrue(rm.CanCardBePlayed(anyColor));
			Assert::IsFalse(rm.CanCardBePlayed(cannotBePlayed));
		}

		void TurnActionShouldContain(TurnAction turnAction)
		{
			std::vector<TurnAction> vectorTurnAction = 
				rm.GetCurrentTurnActionsAvailable();

			Assert::IsTrue(vectorTurnAction.size() > 0);
			Assert::IsTrue(
				DoesVectorContainTurnAction(vectorTurnAction, turnAction));
		}

		void SpecialCardPlacedOnTable(Card cannotBePlayed, Card sameColor,
			Card sameAction, Card anyColor)
		{
			Assert::IsTrue(rm.CanCardBePlayed(sameAction));
			Assert::IsFalse(rm.CanCardBePlayed(cannotBePlayed));
			Assert::IsFalse(rm.CanCardBePlayed(sameColor));
			Assert::IsFalse(rm.CanCardBePlayed(anyColor));
		}

		bool DoesVectorContainTurnAction(std::vector<TurnAction> vector, TurnAction tA)
		{
			if (std::find(vector.begin(), vector.end(), tA) != vector.end())
			{
				return true;
			}
			return false;
		}
	};
}