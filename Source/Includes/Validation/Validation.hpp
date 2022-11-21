#pragma once
#include "..\Constants\Constants.hpp"

bool CheckAnswerValidity(char);
bool IsSymbolLetter(char letterToValidate);
bool IsLetterWasBefore(char letterToCheck, char wordToPrint[amountOfSymbols]);
bool IsHoleWordGuessed(char wordToPrint[amountOfSymbols], int wordLength);
bool IsHoleWordGuessed(char wordToGuess[amountOfSymbols], char wordFromUser[amountOfSymbols], int wordLength);
