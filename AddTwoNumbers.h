#pragma once 
#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode *left = l1, *right = l2;
    	ListNode *res = NULL;
    	ListNode *cur = NULL;
    	int carry = 0;
        while (right != NULL || left != NULL || carry != 0)
        {
        	int sum = 0;
        	if (right != NULL)
        	{
        		sum += right->val;
        		right = right->next;
        	}
        	if (left != NULL)
        	{
        		sum += left->val;
        		left = left->next;
        	}
        	sum += carry;

        	carry = 0;
        	if (sum > 9)
        	{
        		carry = 1;
        		sum -= 10;
        	}

        	if (NULL == cur)
        	{
        		res = new ListNode(sum);
        		cur = res;
        	}
        	else
        	{
        		cur->next = new ListNode(sum);
        		cur = cur->next;
        	}
        }

        return res;
    }
};