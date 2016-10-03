#pragma once
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
    	int blockSize = numRows == 1 ? 1 : 2 * numRows - 2;
    	int blockNum = s.size() % blockSize == 0 ?
    	 s.size() / blockSize : s.size() / blockSize + 1;
    	string res = "";
    	int strLen = s.size();
        for (int i = 0; i < numRows; ++i)
        {
        	for (int j = 0; j < blockNum; j++)
        	{
        		int firstCharIndex = blockSize * j + i;
        		if (firstCharIndex < strLen)
        		{
        			res.push_back(s[firstCharIndex]);
        		}

        		int secCharIndex = blockSize * j + blockSize - i;
        		if (secCharIndex != firstCharIndex && blockSize - i < blockSize &&
        			secCharIndex < strLen)
        		{
        			res.push_back(s[secCharIndex]);
        		}
        	}
        }

        return res;
    }
};