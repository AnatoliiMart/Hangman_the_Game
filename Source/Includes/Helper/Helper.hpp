#pragma once
#include "..\Constants\Constants.hpp"

int GetRandomNumber(int numberOfWords);
int CalculateWordLength(char arr[amountOfWords][amountOfSymbols], int randomIndex);
void FillTheWordToGuess(char arr[amountOfSymbols], char arr2[amountOfWords][amountOfSymbols], int randomIndex, int wordLength);
void FillWordToPrint(char wordToGuess[amountOfSymbols], char wordToPrint[amountOfSymbols], int wordLength);
bool IsLetterPresentInWord(char symbolToValidate, char wordToGuess[amountOfSymbols], char wordToPrint[amountOfSymbols], int wordLength);