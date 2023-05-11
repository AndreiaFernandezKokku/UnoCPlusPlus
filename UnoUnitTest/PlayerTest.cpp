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
			std::vector<Card> playerHand = { BlueZeroCard() };

			std::string expectedName = "TestPlayer";
			std::shared_ptr<std::string> name =
				std::make_shared<std::string>(expectedName);

			InputVariablesManagerMocked mockedInput =
				InitializeMockedInput0();

			Player player = Player{ name, 
				InitializeCardsManagerMock(playerHand), 
				InitializeRulesForPlayerMock(),
				mockedInput };

			Assert::AreEqual(expectedName.c_str(), player.GetName());
			Assert::AreEqual(static_cast<int>(playerHand.size()),
				player.GetCurrentCardsSize());
		}

		TEST_METHOD(HasCardToPlayOnCommonTurn)
		{
			Card cardExpected = RedEightCard();

			std::vector<Card> playerHand = { BlueZeroCard(), cardExpected, 
				GreenOneCard()};

			std::vector<Card> cardsThatCanBePlayed = { cardExpected };

			InputVariablesManagerMocked mockedInput =
				InitializeMockedInput0();

			Player player = Player{ GetCommonPlayerName(), 
				InitializeCardsManagerMock(playerHand),
				InitializeRulesForPlayerMock(cardsThatCanBePlayed),
				mockedInput };
			std::optional<Card> cardPlayed = 
				player.StartTurn(std::vector<TurnAction>{});

			Assert::IsTrue(cardPlayed.has_value());
			Assert::IsTrue(cardExpected == cardPlayed.value());
			Assert::AreEqual(static_cast<int>(playerHand.size()) - 1, 
				player.GetCurrentCardsSize());
		};

		TEST_METHOD(DoesNotHaveCardToPlayOnCommonTurn)
		{
			std::vector<Card> emptyVector = {};
			Card expectedCardToBuy = RedEightCard();

			std::vector<Card> playerHand = { BlueZeroCard(), GreenOneCard() };
			std::vector<Card> cardDeck = { expectedCardToBuy };

			std::vector<Card> cardsThatCanBePlayed = { YellowJumpCard()};

			std::shared_ptr<ICardsManagerDelegate> cardsManagerMock =
				InitializeCardsManagerMock(playerHand, cardDeck, emptyVector);

			InputVariablesManagerMocked mockedInput =
				InitializeMockedInput0();

			Player player = Player{ GetCommonPlayerName(), 
				cardsManagerMock,
				InitializeRulesForPlayerMock(cardsThatCanBePlayed), 
				mockedInput};
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
			std::vector<Card> playerHand = { BlueZeroCard(), GreenOneCard() };

			std::vector<Card> cardsThatCanBePlayed = { BlueZeroCard(), GreenOneCard() };

			InputVariablesManagerMocked mockedInput =
				InitializeMockedInput0();

			Player player = Player{ GetCommonPlayerName(),
				InitializeCardsManagerMock(playerHand),
				InitializeRulesForPlayerMock(cardsThatCanBePlayed), 
				mockedInput};
			std::optional<Card> cardPlayed =
				player.StartTurn(std::vector<TurnAction>{TurnAction::Jumped});

			Assert::IsFalse(cardPlayed.has_value());
		}

		TEST_METHOD(CalledUnoTest)
		{
			Card cardExpected = GreenOneCard();

			std::vector<Card> playerHand = { GreenOneCard(), GreenOneCard() };

			std::vector<Card> cardsThatCanBePlayed = { GreenOneCard() };

			InputVariablesManagerMocked mockedInput =
				InputVariablesManagerMocked{ std::vector<int>{2,0,0} };

			Player player = Player{ GetCommonPlayerName(),
				InitializeCardsManagerMock(playerHand), 
				InitializeRulesForPlayerMock(cardsThatCanBePlayed), 
				mockedInput};

			//Called out uno and played a card
			std::optional<Card> firstCardPlayed =
				player.StartTurn(std::vector<TurnAction>{});

			Assert::IsTrue(firstCardPlayed.has_value());
			Assert::IsTrue(cardExpected == firstCardPlayed.value());
			Assert::AreEqual(1, player.GetCurrentCardsSize());

			//Played last card
			std::optional<Card> secondCardPlayed =
				player.StartTurn(std::vector<TurnAction>{});

			Assert::IsTrue(secondCardPlayed.has_value());
			Assert::IsTrue(cardExpected == secondCardPlayed.value());
			Assert::AreEqual(0, player.GetCurrentCardsSize());
		}

		TEST_METHOD(DidNotCallOutUno)
		{
			//UnoCallOut boolean starts as false, so if we start the player with 
			//just one card it will consider the player did not call uno.
			int cardAmountToBuyIfUnoWasntCalled = 2;
			std::vector<Card> playerHand = { GreenOneCard() };

			std::vector<Card> cardsThatCanBePlayed = { GreenOneCard() };

			std::vector<Card> deckCards = { BlueZeroCard(), YellowJumpCard() };

			InputVariablesManagerMocked mockedInput =
				InitializeMockedInput0();

			Player player = Player{ GetCommonPlayerName(),
				InitializeCardsManagerMock(playerHand, deckCards),
				InitializeRulesForPlayerMock(cardsThatCanBePlayed),
				mockedInput };

			std::optional<Card> cardPlayed =
				player.StartTurn(std::vector<TurnAction>{});

			Assert::IsFalse(cardPlayed.has_value());
			Assert::AreEqual(static_cast<int>(playerHand.size()) + 
				cardAmountToBuyIfUnoWasntCalled, 
				player.GetCurrentCardsSize());
		}

		TEST_METHOD(ShouldBuyDeckCardsButCanThrowCard)
		{
			Card cardExpected = GreenOneCard();

			std::vector<Card> playerHand = { BlueZeroCard(), cardExpected };

			std::vector<Card> cardsThatCanBePlayed = { cardExpected };

			std::vector<Card> deckCards = { BlueZeroCard(), RedEightCard(), GreenOneCard() };

			int amountOfCardsToBuy = 2;

			std::shared_ptr<ICardsManagerDelegate> cardsManagerMock =
				InitializeCardsManagerMock(playerHand, deckCards);

			InputVariablesManagerMocked mockedInput =
				InitializeMockedInput0();

			Player player = Player{ GetCommonPlayerName(),
				cardsManagerMock,
				InitializeRulesForPlayerMock(cardsThatCanBePlayed, amountOfCardsToBuy),
				mockedInput };
			
			std::optional<Card> cardPlayed =
				player.StartTurn(std::vector<TurnAction>{TurnAction::BuyMultipleCard});

			Assert::IsTrue(cardPlayed.has_value());
			Assert::IsTrue(cardExpected == cardPlayed.value());
			Assert::AreEqual(static_cast<int>(deckCards.size()), 
				cardsManagerMock->PrintDeckAmountOfCards());
			Assert::AreEqual(static_cast<int>(playerHand.size()) - 1, 
				player.GetCurrentCardsSize());
		}

		TEST_METHOD(ShouldBuyDeckCardsButCantThrowCard)
		{
			std::vector<Card> playerHand = { BlueZeroCard(), GreenOneCard() };

			std::vector<Card> deckCards = { BlueZeroCard(), RedEightCard(), GreenOneCard() };

			int amountOfCardsToBuy = 2;

			std::shared_ptr<ICardsManagerDelegate> cardsManagerMock =
				InitializeCardsManagerMock(playerHand, deckCards);

			InputVariablesManagerMocked mockedInput =
				InitializeMockedInput0();

			Player player = Player{ GetCommonPlayerName(),
				cardsManagerMock,
				InitializeRulesForPlayerMock({}, amountOfCardsToBuy),
				mockedInput };

			std::optional<Card> cardPlayed =
				player.StartTurn(std::vector<TurnAction>{TurnAction::BuyMultipleCard});

			Assert::IsFalse(cardPlayed.has_value());
			Assert::AreEqual(static_cast<int>(deckCards.size()) - amountOfCardsToBuy,
				cardsManagerMock->PrintDeckAmountOfCards());
			Assert::AreEqual(static_cast<int>(playerHand.size()) + amountOfCardsToBuy,
				player.GetCurrentCardsSize());
		}

		TEST_METHOD(ShouldBuyTableCardsButCanThrowCard)
		{
			Card cardExpected = GreenOneCard();

			std::vector<Card> playerHand = { BlueZeroCard(), cardExpected };

			std::vector<Card> cardsThatCanBePlayed = { cardExpected };

			std::vector<Card> tableCards = { BlueZeroCard(), RedEightCard(), GreenOneCard() };

			int amountOfCardsToBuy = 2;

			std::shared_ptr<ICardsManagerDelegate> cardsManagerMock =
				InitializeCardsManagerMock(playerHand, {}, tableCards);

			InputVariablesManagerMocked mockedInput =
				InitializeMockedInput0();

			Player player = Player{ GetCommonPlayerName(),
				cardsManagerMock,
				InitializeRulesForPlayerMock(cardsThatCanBePlayed, 0, amountOfCardsToBuy),
				mockedInput };

			std::optional<Card> cardPlayed =
				player.StartTurn(std::vector<TurnAction>{TurnAction::BuyMultipleTableCard});

			Assert::IsTrue(cardPlayed.has_value());
			Assert::IsTrue(cardExpected == cardPlayed.value());
			Assert::AreEqual(static_cast<int>(tableCards.size()),
				cardsManagerMock->PrintTableAmountOfCards());
			Assert::AreEqual(static_cast<int>(playerHand.size()) - 1,
				player.GetCurrentCardsSize());
		}

		TEST_METHOD(ShouldBuyTableCardsButCantThrowCard)
		{
			std::vector<Card> playerHand = { BlueZeroCard(), GreenOneCard() };

			std::vector<Card> tableCards = { BlueZeroCard(), RedEightCard(), GreenOneCard() };

			int amountOfCardsToBuy = 2;

			std::shared_ptr<ICardsManagerDelegate> cardsManagerMock =
				InitializeCardsManagerMock(playerHand, {}, tableCards);

			InputVariablesManagerMocked mockedInput =
				InitializeMockedInput0();

			Player player = Player{ GetCommonPlayerName(),
				cardsManagerMock,
				InitializeRulesForPlayerMock({}, 0, amountOfCardsToBuy),
				mockedInput };

			std::optional<Card> cardPlayed =
				player.StartTurn(std::vector<TurnAction>{TurnAction::BuyMultipleTableCard});

			Assert::IsFalse(cardPlayed.has_value());
			Assert::AreEqual(static_cast<int>(tableCards.size()) - amountOfCardsToBuy,
				cardsManagerMock->PrintTableAmountOfCards());
			Assert::AreEqual(static_cast<int>(playerHand.size()) + amountOfCardsToBuy,
				player.GetCurrentCardsSize());
		}

		std::shared_ptr<ICardsManagerDelegate> InitializeCardsManagerMock(
			std::vector<Card> initialCards = {}, std::vector<Card> deckCards = {},
			std::vector<Card> tableCards = {})
		{
			return std::make_shared<CardsManagerMocked>(
				initialCards, deckCards, tableCards);
		}

		std::shared_ptr<IRulesForPlayerDataSource> InitializeRulesForPlayerMock(
			std::vector<Card> cardsThatCanBePlayed = {}, int deckCardsToBuy = 0,
			int tableCardsToBuy = 0)
		{
			return std::make_shared<RulesManagerMocked>(
				cardsThatCanBePlayed, deckCardsToBuy,
				tableCardsToBuy);
		};

		InputVariablesManagerMocked InitializeMockedInput0()
		{
			return InputVariablesManagerMocked(0);
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