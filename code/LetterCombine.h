#pragma once

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) 
	{
		string digitLetterMap[] = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

		char buff[1000];
		vector<string> combineStrs;
		CombineStr(digitLetterMap, digits, buff, 0, combineStrs);

		return combineStrs;
	}

	void CombineStr(const string* digitLetterMap, const string& digits, char* buff, size_t index, vector<string>& combineStrs)
	{
		if (index >= digits.size())
		{
			if (index > 0)
			{
				buff[index] = '\0';
				string str(buff);
				combineStrs.push_back(str);
			}
			return;
		}

		int digit = digits[index] - '0';
		if (digitLetterMap[digit].empty())
		{
			CombineStr(digitLetterMap, digits, buff, index, combineStrs);
			return;
		}

		for (size_t i = 0; i < digitLetterMap[digit].size(); ++i)
		{
			buff[index] = digitLetterMap[digit][i];
			CombineStr(digitLetterMap, digits, buff, index + 1, combineStrs);
		}
	}
};