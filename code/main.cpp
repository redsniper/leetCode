#include <stdio.h>
#include "Utility.h"

#include "SearchRotArr.h"

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
	vector<int> a;
	cin >> a;
	int target;
	cin >> target;

	Solution sol;
	cout << sol.search(a, target) << endl;
}


int main()
{
	InitIO();
	TestSolution();

	return 0;
}