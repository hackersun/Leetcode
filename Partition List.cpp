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
    ListNode *partition(ListNode *head, int x) {
		if(head == NULL) return head;
        ListNode* p = head;
		ListNode* pre = head;
		if(head->val >= x)
		{
			while(pre->next != NULL && pre->next->val >= x)
				pre = pre->next;
			if(pre->next == NULL)return head;
			else{
				ListNode* tmp = pre->next;
				pre->next = tmp->next;
				tmp->next = head;
				head = tmp;
				p = head;
			}
		}

		while(pre->next != NULL)
			if(pre->next->val >= x) pre = pre->next;
			else if(pre == p){
				pre = pre->next;
				p = p->next;
			}else{
				ListNode* tmp = pre->next;
				pre->next = tmp->next;
				tmp->next = p->next;
				p->next = tmp;
				p = p->next;
			}
		return head;
    }
};