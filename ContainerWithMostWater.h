#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int curMaxArea = 0;

        int left = 0, right = height.size() - 1;

        while (left < right)
        {
        	int len = right - left;
        	if (height[left] < height[right])
        	{
        		int area = len * height[left];
        		if (area > curMaxArea)
        		{
        			curMaxArea = area;
        		}

        		int nextLeft = left + 1;
        		while (nextLeft < right && height[nextLeft] <= height[left])
        		{
        			nextLeft ++;
        		}

        		left = nextLeft;
        	}
        	else
        	{
        		int area = len * height[right];
        		if (area > curMaxArea)
        		{
        			curMaxArea = area;
        		}

        		int nextRight = right - 1;
        		while (left < nextRight && height[nextRight] <= height[right])
        		{
        			nextRight --;
        		}

        		right = nextRight;
        	}
        }

        return curMaxArea;
    }
};