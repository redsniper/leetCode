#pragma once
#include <iostream>
#include <vector>

#ifndef NULL
#define NULL 0
#endif

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
	ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
		std::vector<ListNode*> vec;
		
		ListNode* cur = head;
		while (cur)
		{
			vec.push_back(cur);
			cur = cur->next;
		}

		while (n > 1)
		{
			vec.pop_back();
			n--;
		}

		std::vector<ListNode*>::reverse_iterator rit = vec.rbegin();
		ListNode* removeNode = *rit;

		rit++;
		if (rit == vec.rend())
		{
			head = removeNode->next;
			delete removeNode;
		}
		else
		{
			ListNode* preNode = *rit;
			preNode->next = removeNode->next;
			delete removeNode;
		}

		return head;
	}
};