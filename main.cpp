#include "Utility.h"
#include <stdio.h>

#include "RemoveNthNode.h"

void InitIO()
{
	FILE* stream;
	freopen_s(&stream, "./inputData.data", "r", stdin);
	freopen_s(&stream, "./outputData.data", "w", stdout);
}

void TestSolution()
{
	ListNode* listHead;

	std::cin >> listHead;

	int removeIndex;
	std::cin >> removeIndex;

	Solution sol;

	listHead = sol.removeNthFromEnd(listHead, removeIndex);
	std::cout << listHead << std::endl;

	destroyList(listHead);
}


int main()
{
	InitIO();
	TestSolution();

	return 0;
}