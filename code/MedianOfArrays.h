#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalCount = nums1.size() + nums2.size();
        if (totalCount % 2 == 0)
        {
        	double res = FindKthNumInMultiArrays(totalCount / 2,
        		nums1, 0, nums1.size() - 1,
        		nums2, 0, nums2.size() - 1);

        	res += FindKthNumInMultiArrays(totalCount / 2 + 1,
        		nums1, 0, nums1.size() - 1,
        		nums2, 0, nums2.size() - 1);

        	return res / 2.0;
        }
        else
        {
        	return FindKthNumInMultiArrays((totalCount + 1) / 2,
        		nums1, 0, nums1.size() - 1,
        		nums2, 0, nums2.size() - 1);
        }
    }

    int FindKthNumInArray(int k, vector<int>& arr, int beginIndex, int endIndex)
    {
    	if (endIndex - beginIndex + 1 < k)
    	{
    		cout << "FindKthNumInArray Error" << endl;
    		return 0;
    	}

    	return arr[beginIndex + k - 1];
    }

    int FindKthNumInMultiArrays(int k, 
    	vector<int>& arr1, int arr1Begin, int arr1End, 
    	vector<int>& arr2, int arr2Begin, int arr2End)
    {
    	if (arr1Begin > arr1End)
    	{
    		return FindKthNumInArray(k, arr2, arr2Begin, arr2End);
    	}
    	else if (arr2Begin > arr2End)
    	{
    		return FindKthNumInArray(k, arr1, arr1Begin, arr1End);
    	}

    	int mid1 = (arr1Begin + arr1End) / 2,
    		mid2 = (arr2Begin + arr2End) / 2;

    	int preHalfNum = (mid1 + mid2) - (arr1Begin + arr2Begin) + 2;
    	if (arr1[mid1] < arr2[mid2])
    	{
    		if (k < preHalfNum)
    		{
    			return FindKthNumInMultiArrays(k,
    				arr1, arr1Begin, arr1End,
    				arr2, arr2Begin, mid2 - 1);
    		}
    		else
    		{
    			return FindKthNumInMultiArrays(k - (mid1 - arr1Begin + 1),
    				arr1, mid1 + 1, arr1End,
    				arr2, arr2Begin, arr2End);
    		}
    	}
    	else
    	{
    		if (k < preHalfNum)
    		{
    			return FindKthNumInMultiArrays(k,
    				arr1, arr1Begin, mid1 -1,
    				arr2, arr2Begin, arr2End);
    		}
    		else
    		{
    			return FindKthNumInMultiArrays(k - (mid2 - arr2Begin + 1),
    				arr1, arr1Begin, arr1End,
    				arr2, mid2 + 1, arr2End);
    		}
    	}
    }
};