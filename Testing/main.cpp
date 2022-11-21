#include <iostream>

#include "Defines.hpp"
#include "..\Source\Includes\Constants\Constants.hpp"
#include "..\Source\Includes\DataBase\DataBase.hpp"
#include "..\Source\Includes\InputOutput\InputOutput.hpp"
#include "..\Source\Includes\Validation\Validation.hpp"
#include "..\Source\Includes\Helper\Helper.hpp"


int main()
{
	CHECK2(CalculateWordLength, wordsArray, 0, 5, true);
	CHECK2(CalculateWordLength, wordsArray, 0, 6, false);
	CHECK2(CalculateWordLength, wordsArray, 3, 8, true);
	CHECK2(CalculateWordLength, wordsArray, 3, 7, false);

	CHECK1_min(GetRandomNumber, 5, true);
	CHECK1_max(GetRandomNumber, 5, true);
	CHECK1_min(GetRandomNumber, 100, true);
	CHECK1_max(GetRandomNumber, 100, true);
	CHECK1_min(GetRandomNumber, 1, true);
	CHECK1_max(GetRandomNumber, 1, true);

	CHECK3(CompareArrays, FillWordToPrint, sourceArray1, destinationArray1, 1);
	ClearArray(destinationArray1, arraySize);
	CHECK3(CompareArrays, FillWordToPrint, sourceArray1, destinationArray1, 3);
	ClearArray(destinationArray1, arraySize);
	CHECK3(CompareArrays, FillWordToPrint, sourceArray1, destinationArray1, 8);
	ClearArray(destinationArray1, arraySize);

	CHECK1_YN(CheckAnswerValidity, 'a', false);
	CHECK1_YN(CheckAnswerValidity, 'A', false);
	CHECK1_YN(CheckAnswerValidity, '1', false);
	CHECK1_YN(CheckAnswerValidity, 'y', true);
	CHECK1_YN(CheckAnswerValidity, 'Y', true);
	CHECK1_YN(CheckAnswerValidity, 'n', true);
	CHECK1_YN(CheckAnswerValidity, 'N', true);

	CHECK2_arr(IsLetterWasBefore, 'e', sourceArray1, true);
	CHECK2_arr(IsLetterWasBefore, 'i', sourceArray1, false);
	CHECK2_arr(IsLetterWasBefore, 'g', sourceArray1, true);
	CHECK2_arr(IsLetterWasBefore, 'u', sourceArray1, false);




	return 0;
}
