#pragma once
#include <iostream>
#include <vector>

template<typename T>
std::istream& operator >> (std::istream& inStream, std::vector<T>& vec)
{
	int num;
	inStream >> num;

	T value;
	for (int i = 0; i < num; ++i)
	{
		inStream >> value;
		vec.push_back(value);
	}

	return inStream;
}

template<typename T>
std::ostream& operator << (std::ostream& outStream, const std::vector<T>& vec)
{
	outStream << "Vector Size : " << vec.size() << endl;

	for each (const T& value in vec)
	{
		outStream << value << '\t';
	}

	return outStream;
}

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

std::ostream& operator << (std::ostream& ostream, const ListNode* head)
{
	const ListNode* cur = head;

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
