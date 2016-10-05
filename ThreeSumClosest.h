#pragma once
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) 
	{
		sort(nums.begin(), nums.end());

		int closValue = INT_MAX;
		int closSum = 0;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			if (i > 0 && nums[i] == nums[i - 1])
			{
				continue;
			}

			int leftValue = target - nums[i];

			size_t low = i + 1, high = nums.size() - 1;

			while (low < high)
			{
				if (low > i + 1 && nums[low] == nums[low - 1])
				{
					low++;
					continue;
				}

				if (high < nums.size() - 1 && nums[high] == nums[high + 1])
				{
					high--;
					continue;
				}

				int sum = nums[low] + nums[high];

				if (sum > leftValue)
				{
					int diff = sum - leftValue;
					if (diff < closValue)
					{
						closValue = diff;
						closSum = target + diff;
					}

					high--;
				}
				else if (sum < leftValue)
				{
					int diff = leftValue - sum;
					if (diff < closValue)
					{
						closValue = diff;
						closSum = target - diff;
					}

					low++;
				}
				else
				{
					closValue = 0;
					closSum = target;
					break;
				}
			}

			if (closValue == 0)
			{
				break;
			}
		}

		return closSum;
	}
};
