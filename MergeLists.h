#pragma once
#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void destroyList(ListNode* head)
{
	ListNode* cur = head;

	while (cur)
	{
		head = cur->next;
		delete cur;

		cur = head;
	}
}

std::istream& operator >> (std::istream& inStream, ListNode*& headRef)
{
	int len;
	inStream >> len;

	ListNode** head = &headRef;
	for (int i = 0; i < len; ++i)
	{
		int value;
		inStream >> value;
		*head = new ListNode(value);
		head = &(*head)->next;
	}

	return inStream;
}

std::ostream& operator << (std::ostream& ostream, const ListNode* headRef)
{
	const ListNode* cur = headRef;

	while (cur != NULL && cur->next != NULL)
	{
		ostream << cur->val << "->";
		cur = cur->next;
	}

	if (cur)
	{
		ostream << cur->val;
	}

	return ostream;
}

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		ListNode* resultHead = NULL;
		ListNode* preNode = NULL;

		while (NULL != l1 || NULL != l2)
		{
			ListNode* curNode = NULL;
			
			if (l1 != NULL && (l2 == NULL || l1->val <= l2->val))
			{
				curNode = l1;
				l1 = l1->next;
			}
			else if (l2 != NULL && (l1 == NULL || l2->val < l1->val))
			{
				curNode = l2;
				l2 = l2->next;
			}

			if (NULL != preNode)
			{
				preNode->next = curNode;
			}
			preNode = curNode;

			if (NULL == resultHead)
			{
				resultHead = curNode;
			}
		}

		return resultHead;
	}
};