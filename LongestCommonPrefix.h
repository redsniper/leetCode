#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;

        if (strs.empty())
        {
        	return prefix;
        }

        size_t i = 0;

        while (true)
        {
        	if (i >= strs[0].size())
        	{
        		break;
        	}

        	char c = strs[0][i];

        	for (size_t j = 1; j < strs.size(); j++)
        	{
        		if (i >= strs[j].size())
        		{
        			goto Ret;
        		}

        		if (strs[j][i] != c)
        		{
        			goto Ret;
        		}
        	}

        	prefix.push_back(c);

        	i++;
        }

Ret:	return prefix;        
    }
};