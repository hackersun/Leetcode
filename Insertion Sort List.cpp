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
	ListNode *insertionSortList(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* tail = head;
		while (tail->next != NULL) {
			ListNode* p = tail->next;
			tail->next = p->next;
			if (p->val < head->val) {
				p->next = head;
				head = p;
			}
			else {
				ListNode* tmp = head;
				while (tmp != tail && tmp->next->val < p->val)
					tmp = tmp->next;
				if (tmp == tail) {
					p->next = tail->next;
					tail->next = p;
					tail = p;
				}
				else {
					p->next = tmp->next;
					tmp->next = p;
				}
			}
		}
		return head;
	}
};