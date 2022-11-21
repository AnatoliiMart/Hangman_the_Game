#include <cstdlib>
#include <ctime>
#include "..\..\Includes\Helper\Helper.hpp"

int GetRandomNumber(int numberOfWords)
{
	srand(static_cast<unsigned int>(time(NULL)));
	int randomNumber = rand() % (numberOfWords);

	return randomNumber;
}

int CalculateWordLength(char wordsArray[amountOfWords][amountOfSymbols], int randomIndex)
{
	int counter = kZero;

	for (int i = kZero; i < amountOfSymbols && wordsArray[randomIndex][i] != '0'; i++) //!
	{
		++counter;
	}

	return counter;
}

void FillTheWordToGuess(char arr[amountOfSymbols], char arr2[amountOfWords][amountOfSymbols], int randomIndex, int wordLength)
{
	for (int i = kZero; i < wordLength; i++)
	{
		arr[i] = arr2[randomIndex][i];
	}
}

void FillWordToPrint(char wordToGuess[amountOfSymbols], char wordToPrint[amountOfSymbols], int wordLength)
{
	wordToPrint[kZero] = wordToGuess[kZero];
	wordToPrint[wordLength - kOne] = wordToGuess[wordLength - kOne];

	for (int i = kOne; i < wordLength - kOne; i++)
	{
		if (wordToGuess[i] == wordToGuess[kZero])
		{
			wordToPrint[i] = wordToGuess[kZero];
		}
		else if (wordToGuess[i] == wordToGuess[wordLength - kOne])
		{
			wordToPrint[i] = wordToGuess[wordLength - kOne];
		}
		else
		{
			wordToPrint[i] = '_';
		}
	}
}

bool IsLetterPresentInWord(char symbolToValidate, char wordToGuess[amountOfSymbols], char wordToPrint[amountOfSymbols], int wordLength)
{
	bool isLetterPresent = false;

	for (int i = kZero; i < wordLength; i++)
	{
		if (symbolToValidate == wordToGuess[i])
		{
			wordToPrint[i] = wordToGuess[i]; // replace '_' with proper letter(symbolToValidate)
			isLetterPresent = true;
		}
	}

	return isLetterPresent;
}
