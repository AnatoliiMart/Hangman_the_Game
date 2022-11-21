#pragma once

constexpr int amountOfWords = 18;
constexpr int amountOfSymbols = 11;
constexpr int amountOfAttempts = 8;
constexpr int amountSymbolsToReject = 120;

constexpr int kZero = 0;
constexpr int kOne = 1;
constexpr int kTwo = 2;
constexpr int kFive = 5;
constexpr bool WIN = true;
constexpr bool LOOSE = false;

enum class CONSOLE_COLORS
{
	BLACK = 0,
	NAVI = 1,
	GREEN = 2,
	BLUE = 3,
	RED = 4,
	PINK = 5,
	YELLOW = 6,
	WHITE = 7,
	GRAY = 8,

	LIGHT_NAVI = 9,
	LIGHT_GREEN = 10,
	LIGHT_RED = 12,
	LIGHT_PINK = 13,
	LIGHT_YELLOW = 14,
	BRIGHT_WHITE = 15
};

constexpr char letterWasBefore[] = "\n\nThis letter was guessed before, be attentive!";
constexpr char youWasRight[] = "\n\nYou was right, go ahead!";
constexpr char youWasWrong[] = "\n\nYou was wrong, try again!";
constexpr char wrongSymbol[] = "\n\nYou entered wrong symbol, be attentive!";
constexpr char wrongWord[] = "\n\nYou entered wrong word, try again!";
constexpr char invalidMode[] = "\n\nPlease, enter valid mode!";
