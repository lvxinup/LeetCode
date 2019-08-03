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
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return false;
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast != NULL && fast->next != NULL){
			fast = fast->next;
			fast = fast->next;
			slow = slow->next;
			if (slow == fast){
				return true;
			}
		}
		return false;
	}
};