#include <stdio.h>
#include "Utility.h"

#include "ReverseKNodes.h"

using std::cin;
using std::cout;
using std::endl;

void InitIO()
{
	FILE* stream;
	freopen_s(&stream, "./inputData.data", "r", stdin);
	freopen_s(&stream, "./outputData.data", "w", stdout);
}

void TestSolution()
{
	ListNode* listHead = NULL;
	cin >> listHead;

	int k;
	cin >> k;

	Solution sol;
	listHead = sol.reverseKGroup(listHead, k);
	cout << listHead;

	destroyList(listHead);
}


int main()
{
	InitIO();
	TestSolution();

	return 0;
}