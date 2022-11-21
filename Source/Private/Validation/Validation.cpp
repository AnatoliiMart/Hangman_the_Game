#include "..\..\Includes\Validation\Validation.hpp"

bool CheckAnswerValidity(char answer)
{
	bool result = false;

	if ((answer == 'y') || (answer == 'n'))
	{
		result = true;
	}

	return result;
}

bool IsSymbolLetter(char symbolToValidate)
{
	return (((symbolToValidate >= static_cast<int>('A')) && (symbolToValidate <= static_cast<int>('Z')) ||
		(symbolToValidate >= static_cast<int>('a')) && symbolToValidate <= static_cast<int>('z')));
}

bool IsLetterWasBefore(char letterToCheck, char wordToPrint[amountOfSymbols])
{
	bool result = false;

	for (int i = 0; i < amountOfSymbols; i++)
	{
		if (letterToCheck == wordToPrint[i])
		{
			result = true;
		}
	}

	return result;
}

bool IsHoleWordGuessed(char wordToPrint[amountOfSymbols], int wordLength)
{
	int amountOfEmptyCells = kZero;

	for (int i = kZero; i < wordLength; i++)
	{
		if (wordToPrint[i] == '_')
		{
			++amountOfEmptyCells;
			break;
		}
	}

	return !static_cast<bool>(amountOfEmptyCells);
}

bool IsHoleWordGuessed(char wordToGuess[amountOfSymbols], char wordFromUser[amountOfSymbols], int wordLength)
{
	bool isWordGuessed = true;

	for (int i = 0; i < wordLength + kOne; i++)
	{
		if (wordFromUser[i] != wordToGuess[i])
		{
			isWordGuessed = false;
			break;
		}
	}

	return isWordGuessed;
}