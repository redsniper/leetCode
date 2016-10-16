#include <stdio.h>
#include "Utility.h"

#include "MergeKSortedList.h"

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
	vector<ListNode*> inputList;

	std::cin >> inputList;

	Solution sol;

	ListNode* res = sol.mergeKLists(inputList);
	std::cout << res << std::endl;

	destroyList(res);
}


int main()
{
	InitIO();
	TestSolution();

	return 0;
}