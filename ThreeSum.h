#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int> > res;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int leftTarget = - nums[i];

            size_t j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                if (j - 1 >= i + 1 && nums[j] == nums[j - 1])
                {
                    j++;
                    continue;
                }

                if (k + 1 <= nums.size() - 1 && nums[k] == nums[k + 1])
                {
                    k--;
                    continue;
                }

                int sum = nums[j] + nums[k];
                if (sum == leftTarget)
                {
                    vector<int> vec;
                    vec.push_back(nums[i]);
                    vec.push_back(nums[j]);
                    vec.push_back(nums[k]);
                    res.push_back(vec);

                    j++;
                    k--;
                }
                else if (sum > leftTarget)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }

        return res;
    }
};