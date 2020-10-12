#include <iostream>


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		int aLen = 0, bLen = 0;
		ListNode *longL = headA, *shortL = headB;

		while (longL != NULL)
		{
			aLen++;
			longL = longL->next;
		}
		while (shortL != NULL)
		{
			bLen++;
			shortL = shortL->next;
		}

		if (aLen > bLen)
		{
			longL = headA;
			int cont = aLen - bLen;
			while (cont--)
			{
				longL = longL->next;
			}
			shortL = headB;
		}

		if (aLen < bLen)
		{
			longL = headB;
			int cont = bLen - aLen;
			while (cont--)
			{
				longL = longL->next;
			}
			shortL = headA;
		}

		while (longL != NULL && longL->val != shortL->val)
		{
			longL = longL->next;
			shortL = shortL->next;
		}

		if (longL == NULL)
		{
			return NULL;
		}

		return longL;
	}
};