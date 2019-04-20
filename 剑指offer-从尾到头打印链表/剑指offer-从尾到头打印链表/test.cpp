#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<Windows.h>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
		}
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> ArrayList;
		stack<int> cur;
		ListNode* tmp = head;
		while (tmp != NULL)
		{
			cur.push(tmp->val);
			tmp = tmp->next;
		}
		int size = cur.size();
		for (int i = 0; i<size; i++)
		{
			ArrayList.push_back(cur.top());
			cur.pop();
		}

		return ArrayList;
	}

	vector<int> printListFromTailToHead(ListNode* head) {
		
		if (head == NULL)
			return;
		if (head != NULL)
		{
			if (head->next != NULL)
			{
				printListFromTailToHead(head->next);
			}
			tmp.push_back(head->value);
		}
	}
	vector<int> tmp;
};