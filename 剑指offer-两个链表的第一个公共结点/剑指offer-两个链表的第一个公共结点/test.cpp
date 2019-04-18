#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		ListNode* cur1 = pHead1;
		ListNode* cur2 = pHead2;
		long int size1 = 0, size2 = 0;
		if (pHead1 == NULL || pHead2 == NULL)
			return NULL;
		while (cur1)
		{
			cur1 = cur1->next;
			size1++;
		}
		while (cur2)
		{
			cur2 = cur2->next;
			size2++;
		}
		cur1 = pHead1;
		cur2 = pHead2;
		int diff = 0;
		if (size1>size2)
		{
			diff = size1 - size2;
			cur1 = pHead1;
			cur2 = pHead2;
		}
		else
		{
			diff = size2 - size1;
			cur1 = pHead2;
			cur2 = pHead1;
		}
		for (int i = 0; i<diff; i++)
		{
			cur1 = cur1->next;
		}
		while (cur1 != NULL && cur2 != NULL)
		{
			if (cur1 == cur2)
				break;
			cur1 = cur1->next;
			cur2 = cur2->next;
		}

		return cur1;
	}
};
