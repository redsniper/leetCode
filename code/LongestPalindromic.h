#pragma once
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int maxPalindromeLen = 0, maxPalindromeCenter;

        for (int i = 0; i < (int)s.size() * 2 - 1; ++i)
        {
        	int palidromeLen = checkPalindrome(s, i);
        	if (palidromeLen > maxPalindromeLen)
        	{
        		maxPalindromeLen = palidromeLen;
        		maxPalindromeCenter = i;
        	}
        }

        if (maxPalindromeLen % 2 == 0)
        {
        	int begin = (maxPalindromeCenter - 1) / 2 - maxPalindromeLen / 2 + 1;
        	return s.substr(begin, maxPalindromeLen);
        }
        else
        {
        	int begin = maxPalindromeCenter / 2 - (maxPalindromeLen - 1) / 2;
        	return s.substr(begin, maxPalindromeLen);
        }
    }

    int checkPalindrome(const string& s, int midLoc)
    {
    	int left, right;
    	int palindromeLen;

    	if (midLoc % 2 == 0)
    	{
    		left = midLoc / 2 - 1;
    		right = midLoc / 2 + 1;
    		palindromeLen = 1;
    	}
    	else
    	{
    		left = (midLoc - 1) / 2;
    		right = (midLoc + 1) / 2;
    		palindromeLen = 0;
    	}

    	while (left >= 0 && right < (int)s.size())
    	{
    		if (s[left] != s[right])
    		{
    			break;
    		}
    		else
    		{
    			palindromeLen += 2;
    			left--;
    			right++;
    		}
    	}

    	return palindromeLen;
    }
};