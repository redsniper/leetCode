#pragma once

#include <string>
#include <stack>
#include <map>

class Solution {
public:
	bool isValid(std::string s) 
	{
		std::map<char, char> wrapperMap;
		wrapperMap['('] = ')';
		wrapperMap['['] = ']';
		wrapperMap['{'] = '}';

		std::stack<char> wrapperStack;

		for (std::string::iterator it = s.begin(); it != s.end(); ++it)
		{
			std::map<char, char>::iterator curCharFindIt = wrapperMap.find(*it);
			if (curCharFindIt == wrapperMap.end())
			{
				if (wrapperStack.empty())
				{
					return false;
				}

				std::map<char, char>::iterator stackCharFindIt = wrapperMap.find(wrapperStack.top());
				if (stackCharFindIt != wrapperMap.end() && stackCharFindIt->second == *it)
				{
					wrapperStack.pop();
				}
				else
				{
					return false;
				}
			}
			else
			{
				wrapperStack.push(*it);
			}
		}

		return wrapperStack.empty();
	}
};