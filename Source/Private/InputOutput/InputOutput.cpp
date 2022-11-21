#include <windows.h>
#include <iostream> 
#include "..\..\Includes\InputOutput\InputOutput.hpp"


void PrintHeader()
{
	std::cout << "****************************************************************************\n"
		<< "************************* WELCOME TO THE \"HANGMAN\" *************************\n"
		<< "****************************************************************************\n\n";
}

char ConfirmRules()
{
	PrintHeader();

	std::cout << "\t\t     THE RULES AND TERMS:\n\n"
		<< "   You should guess a word using maximum 8 attempts.\n"
		<< "   Every time you can choose between guessing one letter or whole word.\n"
		<< "   Every wrong input leads to deacriasing attempts amount.\n\n"

		<< "\t\tDo you accept THE RULES AND TERMS? (Y/N): ";

	char answer = ' ';

	std::cin >> answer;
	std::cin.ignore(amountSymbolsToReject, '\n');

	return tolower(answer);
}

void PrintWordToPrint(char wordToPrintArray[amountOfSymbols], int wordLength)
{
	std::cout << '\t';

	for (int i = kZero; i < wordLength; i++)
	{
		std::cout << wordToPrintArray[i] << ' ';
	}

	std::cout << '\t';
}

void PrintArrayOfWrongLetters(char arrayOfWrongLetters[amountOfSymbols], int counterOfWrongLetters)
{
	std::cout << "\tList of wrong letters: ";

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = kZero; i < counterOfWrongLetters; i++)
	{
		SetConsoleTextAttribute(hConsole, static_cast<int>(CONSOLE_COLORS::BLUE));
		std::cout << arrayOfWrongLetters[i] << ", ";
		SetConsoleTextAttribute(hConsole, static_cast<int>(CONSOLE_COLORS::WHITE));
	}

	std::cout << std::endl;
}

void PrintAmountOfAttempts(int amountOfAttempt)
{
	std::cout << "You have ";

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned short colorNumber = static_cast<int>(CONSOLE_COLORS::WHITE);

	if (kFive < amountOfAttempt)
	{
		colorNumber = static_cast<int>(CONSOLE_COLORS::LIGHT_GREEN);
	}
	else if ((kFive >= amountOfAttempt) && (kTwo < amountOfAttempt))
	{
		colorNumber = static_cast<int>(CONSOLE_COLORS::LIGHT_YELLOW);
	}
	else if (kTwo >= amountOfAttempt)
	{
		colorNumber = static_cast<int>(CONSOLE_COLORS::LIGHT_RED);
	}

	SetConsoleTextAttribute(hConsole, colorNumber);
	std::cout << amountOfAttempt;
	SetConsoleTextAttribute(hConsole, static_cast<int>(CONSOLE_COLORS::WHITE));

	std::cout << " attempt";

	if (amountOfAttempt > kOne)
	{
		std::cout << "s";
	}

	std::cout << std::endl << std::endl;
}

char GetSymbol()
{
	std::cout << "\n\nGuess the letter...: ";
	char guessedLetter;

	std::cin >> guessedLetter;
	std::cin.ignore(amountSymbolsToReject, '\n');

	return tolower(guessedLetter);
}

void UpdateScreen(char wordToPrintArray[amountOfSymbols], int wordLength, int amountOfAttempt, char arrayOfWrongLetters[amountOfSymbols], int counterOfWrongLetters)
{
	system("cls");
	PrintHeader();
	PrintWordToPrint(wordToPrintArray, wordLength);
	PrintAmountOfAttempts(amountOfAttempt);
	PrintArrayOfWrongLetters(arrayOfWrongLetters, counterOfWrongLetters);
}

void PrintFinalScreen(bool gameResult)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");

	if (gameResult)
	{
		SetConsoleTextAttribute(hConsole, static_cast<int>(CONSOLE_COLORS::LIGHT_GREEN));

		std::cout << "\n\n\n\n\n\n\tdb    db  .d88b.  db    db        db   d8b   db d888888b d8b   db \n"
			<< "\t`8b  d8' .8P  Y8. 88    88        88   I8I   88   `88'   888o  88 \n"
			<< "\t `8bd8'  88    88 88    88        88   I8I   88    88    88V8o 88 \n"
			<< "\t   88    88    88 88    88        Y8   I8I   88    88    88 V8o88 \n"
			<< "\t   88    `8b  d8' 88b  d88        `8b d8'8b d8'   .88.   88  V888 \n"
			<< "\t   YP     `Y88P'  ~Y8888P'         `8b8' `8d8'  Y888888P VP   V8P \n\n\n\n\n\n\n";
	}
	else
	{
		SetConsoleTextAttribute(hConsole, static_cast<int>(CONSOLE_COLORS::LIGHT_RED));

		std::cout << "\n\n\n\n\n\n\tdb    db  .d88b.  db    db      db       .d88b.   .d88b.  .d8888. d88888b \n"
			<< "\t`8b  d8' .8P  Y8. 88    88      88      .8P  Y8. .8P  Y8. 88'  YP 88'     \n"
			<< "\t `8bd8'  88    88 88    88      88      88    88 88    88 `8bo.   88ooooo \n"
			<< "\t   88    88    88 88    88      88      88    88 88    88   `Y8b. 88~~~~~ \n"
			<< "\t   88    `8b  d8' 88b  d88      88booo. `8b  d8' `8b  d8' db   8D 88.     \n"
			<< "\t   YP     `Y88P'  ~Y8888P'      Y88888P  `Y88P'   `Y88P'  `8888Y' Y88888P \n\n\n\n\n\n\n";
	}

	SetConsoleTextAttribute(hConsole, static_cast<int>(CONSOLE_COLORS::WHITE));
}

void PrintGameOverScreen()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");

	SetConsoleTextAttribute(hConsole, static_cast<int>(CONSOLE_COLORS::LIGHT_YELLOW));

	std::cout << "\n\n\n\n\n\n\t d888b   .d8b.  .88b  d88. d88888b       .d88b.  db    db d88888b d8888b. \n"
		<< "\t88' Y8b d8' `8b 88'YbdP`88 88'          .8P  Y8. 88    88 88'     88  `8D \n"
		<< "\t88      88ooo88 88  88  88 88ooooo      88    88 Y8    8P 88ooooo 88oobY' \n"
		<< "\t88  ooo 88~~~88 88  88  88 88~~~~~      88    88 `8b  d8' 88~~~~~ 88`8b   \n"
		<< "\t88. ~8~ 88   88 88  88  88 88.          `8b  d8'  `8bd8'  88.     88 `88. \n"
		<< "\t Y888P  YP   YP YP  YP  YP Y88888P       `Y88P'     YP    Y88888P 88   YD \n\n\n\n\n\n\n";

	SetConsoleTextAttribute(hConsole, static_cast<int>(CONSOLE_COLORS::WHITE));
}

void PrintModeMenu()
{
	std::cout << "\n\n1: Guess a letter\n";
	std::cout << "2: Guess a word\n";
	std::cout << "Choose mode: ";
}

char GetMode()
{
	char choosedMode;
	std::cin >> choosedMode;
	std::cin.ignore(amountSymbolsToReject, '\n');
	std::cin.clear();

	return choosedMode;
}

void PrintStandartArrayWithColor(const char array[], CONSOLE_COLORS color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, static_cast<int>(color));

	for (int i = 0; array[i] != 0; i++)
	{
		std::cout << array[i];
	}

	SetConsoleTextAttribute(hConsole, static_cast<int>(CONSOLE_COLORS::WHITE));
}

void GetWordFromUser(char wordFromUser[amountOfSymbols])
{
	std::cout << "\n\nEnter the word:  ";
	std::cin >> wordFromUser;
	std::cin.ignore(amountSymbolsToReject, '\n');
	std::cin.clear();
}