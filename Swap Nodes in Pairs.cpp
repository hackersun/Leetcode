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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL)return head;
		ListNode* p1 = head;
		head = head->next;
		p1->next = head->next;
		head->next = p1;
		ListNode* p = p1;
		p1 = p1->next;
		while(p1 && p1->next)
		{
			p->next = p1->next;
			p1->next = p->next->next;
			p->next->next = p1;
			p = p1;
			p1 = p1->next;
		}
		return head;
    }
};