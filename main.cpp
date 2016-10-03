#include "Utility.h"
#include <stdio.h>

#include "LongestPalindromic.h"

void InitIO()
{
	FILE* stream;
	freopen_s(&stream, "./inputData.data", "r", stdin);
	freopen_s(&stream, "./outputData.data", "w", stdout);
}

void TestSolution()
{
	Solution sol;
	cout << sol.longestPalindrome("abcdefghijklmnabcdedcba") << endl;
}


int main()
{
	InitIO();
	TestSolution();

	return 0;
}