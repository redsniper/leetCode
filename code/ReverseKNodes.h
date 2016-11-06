#pragma once
#include "Utility.h"

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) 
	{
		ListNode* cur = head;
		int totalLen = 0;
		while (cur)
		{
			totalLen++;
			cur = cur->next;
		}
		
		ListNode* segHead = head;
		cur = segHead;
		ListNode* tail = segHead;

		ListNode* preTail = NULL;
		while (totalLen >= k)
		{
			for (int i = 0; i < k; ++i)
			{
				ListNode* next = cur->next;
				cur->next = segHead;
				tail->next = next;
				segHead = cur;
				cur = next;
			}

			if (tail == head)
			{
				head = segHead;
			}

			if (preTail)
			{
				preTail->next = segHead;
			}

			segHead = cur;
			preTail = tail;
			tail = segHead;

			totalLen -= k;
		}

		return head;
	}
};