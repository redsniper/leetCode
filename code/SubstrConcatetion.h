#pragma once
#include <string>
#include <vector>
#include <unordered_map>
using std::string;
using std::vector;
using std::unordered_map;


class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) 
	{
		if (s.empty() || words.empty())
		{
			return vector<int>();
		}

		unordered_map<string, int> wordDict;
		for (const string& str : words)
		{
			unordered_map<string, int>::iterator it = wordDict.find(str);
			if (it != wordDict.end())
			{
				it->second++;
			}
			else
			{
				wordDict[str] = 1;
			}
		}

		int wLen = words[0].size();
		int sLen = s.size();
		vector<int> res;

		for (int i = 0; i < wLen; ++i)
		{
			int left = i;
			int count = 0;
			unordered_map<string, int> tempDict;
			for (int j = i; j <= sLen - wLen; j += wLen)
			{
				string subWord = s.substr(j, wLen);
				unordered_map<string, int>::iterator wordDictIt = wordDict.find(subWord);
				if (wordDictIt != wordDict.end())
				{
					unordered_map<string, int>::iterator it = tempDict.find(subWord);
					if (it != tempDict.end())
					{
						it->second++;
						count++;

						while (it->second > wordDictIt->second)
						{
							string removeWord = s.substr(left, wLen);
							left += wLen;
							tempDict[removeWord]--;
							count--;
						}
					}
					else
					{
						tempDict[subWord] = 1;
						count++;
					}

					if (count == (int)words.size())
					{
						res.push_back(left);
					}
				}
				else
				{
					left = j + wLen;
					tempDict.clear();
					count = 0;
				}
			}
		}

		return res;
	}
};