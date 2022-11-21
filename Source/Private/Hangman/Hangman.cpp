#include <windows.h>
#include <iostream>

#include "..\..\Includes\Constants\Constants.hpp"
#include "..\..\Includes\DataBase\DataBase.hpp"
#include "..\..\Includes\InputOutput\InputOutput.hpp"
#include "..\..\Includes\Validation\Validation.hpp"
#include "..\..\Includes\Helper\Helper.hpp"

void RunHangman()
{
	bool isAnswerValid = false;
	char answer = ' ';

	while (!isAnswerValid)
	{
		system("cls");
		answer = ConfirmRules();
		isAnswerValid = CheckAnswerValidity(answer);
	}

	if (answer == 'n')
	{
		PrintGameOverScreen();
		exit(0);
	}

	int indexOfRandomWord = GetRandomNumber(amountOfWords);

	int wordLength = CalculateWordLength(wordsArray, indexOfRandomWord);

	char wordToGuess[amountOfSymbols]{};
	FillTheWordToGuess(wordToGuess, wordsArray, indexOfRandomWord, wordLength);

	char wordToPrint[amountOfSymbols]{};
	FillWordToPrint(wordToGuess, wordToPrint, wordLength);

	int attemptCounter = amountOfAttempts;
	char arrayOfWrongLetters[amountOfSymbols]{};
	int counterOfWrongLetters = kZero;

	UpdateScreen(wordToPrint, wordLength, attemptCounter, arrayOfWrongLetters, counterOfWrongLetters);

	while (attemptCounter > kZero)
	{
		PrintModeMenu();
		char choosedMode = GetMode();

		if ('1' == choosedMode)
		{
			UpdateScreen(wordToPrint, wordLength, attemptCounter, arrayOfWrongLetters, counterOfWrongLetters);

			char symbolToValidate = GetSymbol();

			if (IsSymbolLetter(symbolToValidate))
			{
				if (IsLetterWasBefore(symbolToValidate, wordToPrint))
				{
					
					UpdateScreen(wordToPrint, wordLength, attemptCounter, arrayOfWrongLetters, counterOfWrongLetters);
					PrintStandartArrayWithColor(letterWasBefore, CONSOLE_COLORS::LIGHT_RED);
				}
				else
				{			
					bool isLetterPresent = IsLetterPresentInWord(symbolToValidate, wordToGuess, wordToPrint, wordLength);

					if (IsHoleWordGuessed(wordToPrint, wordLength))
					{
						PrintFinalScreen(WIN);
						exit(0);
					}

					if (isLetterPresent)
					{
						UpdateScreen(wordToPrint, wordLength, attemptCounter, arrayOfWrongLetters, counterOfWrongLetters);
						PrintStandartArrayWithColor(youWasRight, CONSOLE_COLORS::LIGHT_GREEN);
					}
					else
					{
						arrayOfWrongLetters[counterOfWrongLetters] = symbolToValidate;
						--attemptCounter;
						++counterOfWrongLetters;
						UpdateScreen(wordToPrint, wordLength, attemptCounter, arrayOfWrongLetters, counterOfWrongLetters);
						PrintStandartArrayWithColor(youWasWrong, CONSOLE_COLORS::LIGHT_RED);
					}
				}
			}
			else
			{
				--attemptCounter;
				UpdateScreen(wordToPrint, wordLength, attemptCounter, arrayOfWrongLetters, counterOfWrongLetters);
				PrintStandartArrayWithColor(wrongSymbol, CONSOLE_COLORS::LIGHT_RED);
			}
		}
		else if('2' == choosedMode)
		{
			UpdateScreen(wordToPrint, wordLength, attemptCounter, arrayOfWrongLetters, counterOfWrongLetters);
			char wordFromUser[amountOfSymbols]{};
			GetWordFromUser(wordFromUser);

			if (IsHoleWordGuessed(wordToGuess, wordFromUser, wordLength))
			{
				PrintFinalScreen(WIN);
				exit(0);
			}
			else
			{
				--attemptCounter;
				UpdateScreen(wordToPrint, wordLength, attemptCounter, arrayOfWrongLetters, counterOfWrongLetters);
				PrintStandartArrayWithColor(wrongWord, CONSOLE_COLORS::LIGHT_RED);
			}
		}
		else
		{
			UpdateScreen(wordToPrint, wordLength, attemptCounter, arrayOfWrongLetters, counterOfWrongLetters);
			PrintStandartArrayWithColor(invalidMode, CONSOLE_COLORS::LIGHT_RED);
		}		
	}

	if (kZero == attemptCounter)
	{
		PrintFinalScreen(LOOSE);
	}
}
