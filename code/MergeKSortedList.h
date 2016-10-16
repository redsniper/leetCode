#pragma once
#include <vector>
#include "Utility.h"
#include <queue>

using std::vector;
using std::priority_queue;

class Solution {
public:
	class comparer
	{
	public:
		bool operator() (const ListNode* a, const ListNode* b)
		{
			return a->val >= b->val;
		}
	};

	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		ListNode* header = new ListNode(0);
		ListNode* curNode = header;

		priority_queue<ListNode*, vector<ListNode*>, comparer> pQueue;

		for (ListNode* node : lists)
		{
			if (node)
			{
				pQueue.push(node);
			}
		}

		while (!pQueue.empty())
		{
			auto firstNode = pQueue.top();
			curNode->next = firstNode;
			curNode = curNode->next;

			pQueue.pop();
			
			if (firstNode->next)
			{
				pQueue.push(firstNode->next);
			}
		}

		curNode = header->next;
		delete header;

		return curNode;
	}
};