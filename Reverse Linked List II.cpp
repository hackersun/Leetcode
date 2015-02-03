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
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)return head;
		ListNode* tmp = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return tmp;
	}

	ListNode *reverseBetween(ListNode *head, int m, int n) {
		int index = 1;
		ListNode* p = head;
		while (index < m - 1) { p = p->next; index++; }
		ListNode* q = p;
		while (index < n) { q = q->next; index++; }
		ListNode* tmp = q;
		q = q->next;
		tmp->next = NULL;
		if (m == 1) {
			tmp = reverseList(head);
			head->next = q;
			return tmp;
		}
		tmp = reverseList(p->next);
		p->next->next = q;
		p->next = tmp;
		return head;
	}
};