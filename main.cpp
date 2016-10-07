#include <stdio.h>
#include "Utility.h"

#include "MergeLists.h"

void InitIO()
{
	FILE* stream;
	freopen_s(&stream, "./inputData.data", "r", stdin);
	freopen_s(&stream, "./outputData.data", "w", stdout);
}

void TestSolution()
{
	ListNode *a, *b;

	std::cin >> a >> b;
	Solution sol;
	ListNode* mergeResult = sol.mergeTwoLists(a, b);
	std::cout << mergeResult << std::endl;
}


int main()
{
	InitIO();
	TestSolution();

	return 0;
}