#define  _CRT_SECURE_NO_WARNINGS 1

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
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode* p = pHead;
		stack<ListNode* > s;
		while (p->next)
		{
			s.push(p);
			p = p->next;
		}
		ListNode* head = p;
		while (!s.empty())
		{
			p->next = s.top();
			p = p->next;
			s.pop();
		}
		p->next = NULL;
		return head;
	}
};