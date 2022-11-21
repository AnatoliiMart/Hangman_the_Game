#pragma once
#include "..\Constants\Constants.hpp"

void PrintHeader();
char ConfirmRules();
void PrintWordToPrint(char wordToPrintArray[amountOfSymbols], int wordLength);
void PrintArrayOfWrongLetters(char arrayOfWrongLetters[amountOfSymbols], int counterOfWrongLetters);
void PrintAmountOfAttempts(int amountOfAttempt);
char GetSymbol();
void UpdateScreen(char wordToPrintArray[amountOfSymbols], int wordLength, int amountOfAttempt, char arrayOfWrongLetters[amountOfSymbols], int counterOfWrongLetters);
void PrintFinalScreen(bool gameResult);
void PrintGameOverScreen();
void PrintModeMenu();
char GetMode();
void PrintStandartArrayWithColor(const char array[], CONSOLE_COLORS color);
void GetWordFromUser(char wordFromUser[amountOfSymbols]);