#include "pch.h"
#include "CppUnitTest.h"
#include "../UnoCPlusPlus/Player/Player.h"
#include "CardsManagerMock/CardsManagerMocked.h"
#include "RulesManagerMock/RulesManagerMocked.h"
#include "InputVariablesManagerMock/InputVariablesManagerMocked.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnoUnitTest
{
	TEST_CLASS(PlayerTest)
	{
	public:
		TEST_METHOD(TestPlayerInitialization)
		{
			std::vector<Card> emptyVector = {};

			std::vector<Card> playerHand = { BlueZeroCard() };

			std::string expectedName = "TestPlayer";
			std::shared_ptr<std::string> name =
				std::make_shared<std::string>(expectedName);

			std::shared_ptr<CardsManagerMocked> cardsManagerMock =
				InitializeCardsManagerMock(playerHand, emptyVector, emptyVector);

			std::shared_ptr<RulesManagerMocked> rulesForPlayerMock =
				InitializeRulesForPlayerMock(emptyVector, 0, 0);

			InputVariablesManagerMocked mockedInput =
				InitializeMockedInput0();

			Player player = Player{ name, cardsManagerMock, rulesForPlayerMock,
				mockedInput };

			Assert::AreEqual(expectedName.c_str(), player.GetName());
			Assert::AreEqual(static_cast<int>(playerHand.size()),
				player.GetCurrentCardsSize());
		}

		TEST_METHOD(HasCardToPlayOnCommonTurn)
		{
			std::vector<Card> emptyVector = {};
			Card cardExpected = RedEightCard();

			std::vector<Card> playerHand = { BlueZeroCard(), cardExpected, 
				GreenOneCard()};

			std::vector<Card> cardsThatCanBePlayed = { cardExpected };

			std::shared_ptr<CardsManagerMocked> cardsManagerMock =
				InitializeCardsManagerMock(playerHand, emptyVector, emptyVector);

			std::shared_ptr<RulesManagerMocked> rulesForPlayerMock =
				InitializeRulesForPlayerMock(cardsThatCanBePlayed,0,0);

			InputVariablesManagerMocked mockedInput =
				InitializeMockedInput0();

			Player player = Player{ GetCommonPlayerName(), cardsManagerMock, 
				rulesForPlayerMock,	mockedInput };
			std::optional<Card> cardPlayed = 
				player.StartTurn(std::vector<TurnAction>{});

			Assert::IsTrue(cardPlayed.has_value());
			Assert::IsTrue(cardExpected == cardPlayed.value());
			Assert::AreEqual(0, player.GetCurrentCardsSize());
		};

		TEST_METHOD(DoesNotHaveCardToPlayOnCommonTurn)
		{
			std::vector<Card> emptyVector = {};
			Card expectedCardToBuy = RedEightCard();

			std::vector<Card> playerHand = { BlueZeroCard(), GreenOneCard() };
			std::vector<Card> cardDeck = { expectedCardToBuy };

			std::vector<Card> cardsThatCanBePlayed = { YellowJumpCard()};

			std::shared_ptr<CardsManagerMocked> cardsManagerMock =
				InitializeCardsManagerMock(playerHand, cardDeck, emptyVector);

			std::shared_ptr<RulesManagerMocked> rulesForPlayerMock =
				InitializeRulesForPlayerMock(cardsThatCanBePlayed, 0, 0);

			InputVariablesManagerMocked mockedInput =
				InitializeMockedInput0();

			Player player = Player{ GetCommonPlayerName(), 
				cardsManagerMock, rulesForPlayerMock, mockedInput };
			std::optional<Card> cardPlayed =
				player.StartTurn(std::vector<TurnAction>{});

			Assert::IsFalse(cardPlayed.has_value());
			//Bought a card
			Assert::AreEqual(static_cast<int>(playerHand.size()) + 1, 
				player.GetCurrentCardsSize());
			Assert::AreEqual(0, cardsManagerMock->PrintDeckAmountOfCards());
		}

		TEST_METHOD(PlayerGotJumpedTest)
		{
			std::vector<Card> emptyVector = {};
			std::optional<Card> cardExpected = std::nullopt;

			std::vector<Card> playerHand = { BlueZeroCard(), GreenOneCard() };

			std::vector<Card> cardsThatCanBePlayed = { BlueZeroCard(), GreenOneCard() };

			std::shared_ptr<CardsManagerMocked> cardsManagerMock =
				InitializeCardsManagerMock(playerHand, emptyVector, emptyVector);

			std::shared_ptr<RulesManagerMocked> rulesForPlayerMock =
				InitializeRulesForPlayerMock(cardsThatCanBePlayed, 0, 0);

			InputVariablesManagerMocked mockedInput =
				InitializeMockedInput0();

			Player player = Player{ GetCommonPlayerName(),
				cardsManagerMock, rulesForPlayerMock, mockedInput };
			std::optional<Card> cardPlayed =
				player.StartTurn(std::vector<TurnAction>{TurnAction::Jumped});

			Assert::IsFalse(cardPlayed.has_value());
		}

		std::shared_ptr<CardsManagerMocked> InitializeCardsManagerMock(
			std::vector<Card> initialCards, std::vector<Card> deckCards, 
			std::vector<Card> tableCards)
		{
			return std::make_shared<CardsManagerMocked>(
				initialCards, deckCards, tableCards);
		}

		std::shared_ptr<RulesManagerMocked> InitializeRulesForPlayerMock(
			std::vector<Card> cardsThatCanBePlayed, int deckCardsToBuy, 
			int tableCardsToBuy)
		{
			return std::make_shared<RulesManagerMocked>(
				cardsThatCanBePlayed, deckCardsToBuy,
				tableCardsToBuy);
		};

		InputVariablesManagerMocked InitializeMockedInput0()
		{
			return InputVariablesManagerMocked(0, "");
		};

		std::shared_ptr<std::string> GetCommonPlayerName()
		{
			return std::make_shared<std::string>("CommonName");
		}

		Card BlueZeroCard()
		{
			return Card{ Color::Blue, CardAction::Zero };
		}

		Card RedEightCard()
		{
			return Card{ Color::Red, CardAction::Eight };
		}

		Card GreenOneCard()
		{
			return Card{ Color::Green, CardAction::One };
		}

		Card YellowJumpCard()
		{
			return Card{ Color::Yellow, CardAction::Jump };
		}
	};
}