#include "Utility.h"
#include <stdio.h>

#include "LetterCombine.h"

void InitIO()
{
	FILE* stream;
	freopen_s(&stream, "./inputData.data", "r", stdin);
	freopen_s(&stream, "./outputData.data", "w", stdout);
}

void TestSolution()
{
	string digits;
	std::cin >> digits;

	Solution sol;
	std::cout << sol.letterCombinations(digits) << endl;
}


int main()
{
	InitIO();
	TestSolution();

	return 0;
}