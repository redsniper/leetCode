#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct NumIndex
{
	int num;
	int index;
};

int find(const vector<NumIndex>& numArray, int target);
bool compare(const NumIndex& a, const NumIndex& b);

vector<int> twoSum(vector<int>& nums, int target) 
{
	vector<int> res;
	res.push_back(-1);
	res.push_back(-1);

	vector<NumIndex> sortNums;
	for (size_t i = 0; i < nums.size(); ++i)
	{
		NumIndex numIndex;
		numIndex.num = nums[i];
		numIndex.index = i;
		sortNums.push_back(numIndex);
	}

	sort(sortNums.begin(), sortNums.end(), compare);

	for (size_t i = 0; i < sortNums.size(); ++i)
	{
		cout << sortNums[i].num << ", " << sortNums[i].index << endl;
	}

	for (size_t i = 0; i < sortNums.size(); ++i)
	{
		int leftValue = target - sortNums[i].num;
		int findIndex = find(sortNums, leftValue);
		if (findIndex >= 0 && (size_t)findIndex != i)
		{
			if (sortNums[i].index < sortNums[findIndex].index)
			{
				res[0] = sortNums[i].index;
				res[1] = sortNums[findIndex].index;
			}
			else
			{
				res[0] = sortNums[findIndex].index;
				res[1] = sortNums[i].index;
			}

			break;
		}
	}

	return res;
}