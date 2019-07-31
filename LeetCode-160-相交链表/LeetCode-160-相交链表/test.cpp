#define  _CRT_SECURE_NO_WARNINGS 1

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB)    return nullptr;
		ListNode* cur1 = headA;
		ListNode* cur2 = headB;
		int lengthA = 0, lengthB = 0;
		while (cur1){
			cur1 = cur1->next;
			lengthA++;
		}
		while (cur2){
			cur2 = cur2->next;
			lengthB++;
		}
		if (lengthA>lengthB){
			int flag = lengthA - lengthB;
			while (flag){
				headA = headA->next;
				flag--;
			}
		}
		else{
			int flag = lengthB - lengthA;
			while (flag){
				headB = headB->next;
				flag--;
			}
		}
		while (headA){
			if (headA == headB)  return headA;
			headA = headA->next;
			headB = headB->next;
		}
		return nullptr;
	}
};