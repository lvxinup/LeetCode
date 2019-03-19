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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* cur = new ListNode(-1);
		ListNode* tmp = cur;
		int flag = 0;
		while (l1 || l2)
		{
			int val1 = l1 ? l1->val : 0;
			int val2 = l2 ? l2->val : 0;
			int sum = val1 + val2 + flag;
			flag = sum / 10;
			tmp->next = new ListNode(sum % 10);
			tmp = tmp->next;
			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		}
		if (flag)
			tmp->next = new ListNode(1);
		return cur->next;
	}
};