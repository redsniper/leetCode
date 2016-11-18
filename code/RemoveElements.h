#pragma once
#include <vector>
using std::vector;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) 
	{
		int begin = 0;
		int end = (int)nums.size() - 1;

		while (begin <= end)
		{
			if (nums[begin] == val)
			{
				nums[begin] = nums[end];
				nums[end] = val;
				end--;
			}
			else
			{
				begin++;
			}
		}

		vector<int>::iterator it = nums.begin();
		for (int i = 0; i <= end; ++i)
		{
			++it;
		}

		nums.erase(it, nums.end());

		return (int)nums.size();
	}
};