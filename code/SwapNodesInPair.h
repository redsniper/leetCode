#pragma once
#include "Utility.h"

class Solution {
public:
	ListNode* swapPairs(ListNode* head) 
	{
		ListNode* header = new ListNode(0);
		header->next = head;
		ListNode* cur = header;

		while (cur->next != NULL && cur->next->next != NULL)
		{
			ListNode* temp = cur->next;
			cur->next = cur->next->next;
			temp->next = cur->next->next;
			cur->next->next = temp;

			cur = cur->next->next;
		}

		head = header->next;
		delete header;

		return head;
	}
};
