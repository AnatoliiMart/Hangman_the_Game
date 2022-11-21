

//#define EXPRESSION_TO_RESULT(expression) 
#define OUTPUT_NAME(name) std::cout << "Testing function " << #name << "() : "
#define OUTPUT_EXPRESSION(expression) ((expression) ? std::cout << "Test PASSED\n" : std::cout << "Test FAILED\n");
#define PRINT_RESULT(name, expression)  OUTPUT_NAME(name); OUTPUT_EXPRESSION(expression)


#define CHECK1_min(foo, arg1, expectation) \
		PRINT_RESULT(foo, ((foo(arg1) >= 0) == expectation ? true : false)) 

#define CHECK1_max(foo, arg1, expectation) \
		PRINT_RESULT(foo, ((foo(arg1) <= (arg1 - 1)) == expectation ? true : false)) 

#define CHECK2(foo, arg1, arg2, comparison, expectation) \
		PRINT_RESULT(foo, (foo(arg1, arg2) == comparison) == expectation ? true : false)


#define FILL_ARRAY(foo, arg1, arg2, arg3) foo(arg1, arg2, arg3)
#define COMPARE_ARRAY(bar, arg1, arg2, arg3) bar(arg1, arg2, arg3)
#define CHECK3(bar, foo, arg1, arg2, arg3)	\
		FILL_ARRAY(foo, arg1, arg2, arg3);				\
		PRINT_RESULT(foo, (COMPARE_ARRAY(bar, arg1, arg2, arg3)));


#define CHECK1_YN(foo, arg1, expectation) \
		PRINT_RESULT(foo, ((arg1 == 'y' ? true : (arg1 == 'Y' ? true : (arg1 == 'n' ? true : (arg1 == 'N' ? true : false)))) \
										 == expectation ? true : false))

#define FIND_LETTER(foo, arg1, arg2) foo(arg1, arg2)
#define CHECK2_arr(foo, arg1, arg2, expectation) \
		PRINT_RESULT(foo, ((FIND_LETTER(foo, arg1, arg2) == expectation) ? true : false ))




//help functions and variables


const int arraySize = 8;
char sourceArray1[arraySize] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
char destinationArray1[arraySize] = {};

bool CompareArrays(char arr1[], char arr2[], int wordLength)
{
	bool result = true;

	for (int i = 0; i < wordLength; i++)
	{
		if (arr1[i] != arr2[i])
		{
			result = false;
		}

		break;
	}

	return result;
}

void ClearArray(char arr1[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		arr1[i] = ' ';
	}
}