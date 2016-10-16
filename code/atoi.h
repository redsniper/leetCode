#pragma once
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty())
        {
            return 0;
        }

        int sign = 1;

        string::iterator it = str.begin();

        while (*it == ' ')
        {
            ++it;
            if (it == str.end())
            {
                return 0;
            }
        }

        if (*it == '-')
        {
            sign = -1;
            ++it;
        }
        else if (*it == '+')
        {
            ++it;
        }

        int res = 0;
        while (it != str.end())
        {
            int digit = *it - '0';
            if (digit < 0 || digit > 9)
            {
                return res;
            }

            if (sign > 0 && INT_MAX / 10 < res)
            {
                return INT_MAX;
            }
            else if (sign < 0 && INT_MIN / 10 > res)
            {
                return INT_MIN;
            }

            res *= 10;

            if (sign > 0 && INT_MAX - digit < res)
            {
                return INT_MAX;
            }
            else if (sign < 0 && INT_MIN + digit > res)
            {
                return INT_MIN;
            }

            res += digit * sign;

            ++it;
        }

        return res;
    }
};