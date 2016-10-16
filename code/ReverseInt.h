#pragma once
#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int sign = x < 0 ? -1 : 1;

        int res = 0;
        x *= sign;
        while (x > 0)
        {
        	int reminder = x % 10;
        	if (INT_MAX / 10 < res)
        	{
        		return 0;
        	}
        	res *= 10;
        	if (INT_MAX - reminder < res)
        	{
        		return 0;
        	}
        	res += reminder;
        	
        	x /= 10;
        }

        return res * sign;
    }
};