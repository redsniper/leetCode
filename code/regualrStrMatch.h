#pragma once
#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }

    struct rec
    {
    	size_t sIndex;
    	size_t pIndex;
    };

    bool isMatch(string& s, size_t sIndex, string& p, size_t pIndex)
    {
    	if (sIndex == s.size() && pIndex == p.size())
    	{
    		return true;
    	}
    	else if (sIndex != s.size() && pIndex == p.size())
    	{
    		return false;
    	}

    	if (pIndex + 1 < p.size() && '*' == p[pIndex + 1])
    	{
    		if (isMatch(s, sIndex, p, pIndex + 2))
    		{
    			return true;
    		}

    		if ('.' == p[pIndex])
    		{
    			while (sIndex != s.size())
    			{
    				if (isMatch(s, sIndex + 1, p, pIndex + 2))
    				{
    					return true;
    				}

    				sIndex ++;
    			} 
    		}
    		else
    		{
    			while (s[sIndex] == p[pIndex] && sIndex != s.size())
    			{
    				if (isMatch(s, sIndex + 1, p, pIndex + 2))
    				{
    					return true;
    				}

    				sIndex ++;
    			}
    		}
    		return false;
    	}
    	else if ('.' == p[pIndex] && sIndex < s.size())
    	{
    		return isMatch(s, sIndex + 1, p, pIndex + 1);
    	}
    	else if (sIndex < s.size() && s[sIndex] == p[pIndex])
    	{
    		return isMatch(s, sIndex + 1, p, pIndex + 1);
    	}

    	return false;
    }
};