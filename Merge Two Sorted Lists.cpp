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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
		if(l2 == NULL) return l1;
		ListNode* ph = l1->val < l2->val ? l1 : l2;
		ListNode* head = ph;
		if(ph == l1)
			l1 = l1->next;
		else
			l2 = l2->next;
		while(l1 && l2)
		{
			ListNode* tmp = l1->val < l2->val ? l1 : l2;
			ph->next = tmp;
			ph = ph->next;
			if(tmp == l1) l1 = l1->next;
			else l2 = l2->next;
		}
		if(l1 == NULL) ph->next = l2;
		else ph->next = l1;
		return head;
    }
};