#pragma once
#include <vector>
using std::vector;

class Solution {
public:
	int search(vector<int>& nums, int target) 
	{
		return searchRot(nums, target, 0, (int)nums.size() - 1);
	}

	int searchNormal(const vector<int>& nums, int target, int low, int high)
	{
		if (high < low)
		{
			return -1;
		}

		int mid = (low + high) / 2;

		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] > target)
		{
			return searchNormal(nums, target, low, mid - 1);
		}
		else
		{
			return searchNormal(nums, target, mid + 1, high);
		}
	}

	int searchRot(const vector<int>& nums, int target, int low, int high)
	{
		if (high < low)
		{
			return -1;
		}

		int mid = (low + high) / 2;

		if (target == nums[mid])
		{
			return mid;
		}
		else if (target < nums[mid])
		{
			if (nums[low] <= nums[mid])
			{
				if (target >= nums[low])
				{
					return searchNormal(nums, target, low, mid - 1);
				}
				else
				{
					return searchRot(nums, target, mid + 1, high);
				}
			}
			else
			{
				return searchRot(nums, target, low, mid - 1);
			}
		}
		else
		{
			if (nums[mid] < nums[high])
			{
				if (target <= nums[high])
				{
					return searchNormal(nums, target, mid + 1, high);
				}
				else
				{
					return searchRot(nums, target, low, mid - 1);
				}
			}
			else
			{
				return searchRot(nums, target, mid + 1, high);
			}
		}
	}
};