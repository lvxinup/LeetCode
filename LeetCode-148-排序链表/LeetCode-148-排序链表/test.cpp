#define  _CRT_SECURE_NO_WARNINGS 1

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		int x[100000];
		int i = 0, k = 0;
		struct ListNode* p;
		p = head;
		while (p)
		{
			x[i] = p->val;
			p = p->next;
			i++;
		}
		sort(x, x + i);
		p = head;
		while (p)
		{
			p->val = x[k];
			p = p->next;
			k++;
		}
		return head;
	}
};