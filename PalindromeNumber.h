#pragma once
#include <iostream>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }

        if (x < 10)
        {
            return true;
        }

        int numLn = 1;
        while (x / numLn >= 10)
        {
            numLn *= 10;
        }

        while (numLn > 1)
        {
            int highDig = x / numLn;
            int lowDig = x % 10;

            if (highDig != lowDig)
            {
                return false;
            }

            x = (x - highDig * numLn) / 10;

            numLn /= 100;
        }

        return true;
    }
};