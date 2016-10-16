#pragma once
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int charLoc[256];

		for (int i = 0; i < 256; i++)
		{
			charLoc[i] = -1;
		}

		int res = 0;
		int curLen = 0;

		for (size_t i = 0; i < s.length(); i++)
		{
			unsigned char loc = s[i];
			if (charLoc[loc] < 0)
			{
				curLen++;
			}
			else
			{
				int repeatLen = i - charLoc[loc];
				curLen++;

				curLen = curLen < repeatLen ? curLen : repeatLen;
			}

			charLoc[loc] = i;
			if (curLen > res)
			{
				res = curLen;
			}
		}

		return res;
	}
};