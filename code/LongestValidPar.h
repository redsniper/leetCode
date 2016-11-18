#pragma once
#include <string>
using std::string;

class Solution {
public:
	int longestValidParentheses(string s) 
	{
		int* d = new int[s.length()];
		memset(d, 0, s.length() * sizeof(int));
		int maxLen = 0;

		for (int i = 1; i < (int)s.length(); ++i)
		{
			if (s[i] == ')')
			{
				int leftParIndex = i - d[i - 1] - 1;

				if (leftParIndex >= 0 && s[leftParIndex] == '(')
				{
					d[i] = d[i - 1] + 2;
					if (leftParIndex > 0)
					{
						d[i] += d[leftParIndex - 1];
					}

					if (d[i] > maxLen)
					{
						maxLen = d[i];
					}
				}
			}
		}

		delete[] d;
		return maxLen;
	}
};