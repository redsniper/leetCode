#pragma once
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
	void nextPermutation(vector<int>& nums) 
	{
		int edge = nums.size() - 1;

		while (edge > 0)
		{
			if (nums[edge - 1] < nums[edge])
			{
				break;
			}

			--edge;
		}

		if (edge > 0)
		{
			for (int i = nums.size() - 1; i >= edge; --i)
			{
				if (nums[i] > nums[edge - 1])
				{
					int temp = nums[edge - 1];
					nums[edge - 1] = nums[i];
					nums[i] = temp;
					break;
				}
			}
		}

		if (!nums.empty())
		{
			int low = edge, high = nums.size() - 1;
			while (low < high)
			{
				int temp = nums[low];
				nums[low] = nums[high];
				nums[high] = temp;
				++low;
				--high;
			}
		}
	}
};