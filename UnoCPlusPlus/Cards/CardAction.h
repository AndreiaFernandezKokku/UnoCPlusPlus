#pragma once

enum class CardAction
{
	Zero = 0,
	One = 1,
	Two = 2,
	Three = 3,
	Four = 4,
	Five = 5,
	Six = 6,
	Seven = 7,
	Eight = 8,
	Nine = 9,
	PlusTwo = 10,
	Reverse = 11,
	Jump = 12,
	PlusFour = 13,
	Count = 14,
};

static const char* CardActionToString[] = {
	"0",
	"1",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"+2",
	"Reverse",
	"Jump",
	"+4",
};