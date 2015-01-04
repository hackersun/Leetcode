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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL || n < 1) return head;
		ListNode* fast = head;
		ListNode* slow = head;
		while(n-- && fast != NULL) fast = fast->next;
		if(fast == NULL){
			head = head->next;
			delete slow;
			return head;
		}
		while(fast->next){
			fast = fast->next;
			slow = slow->next;
		}
		fast = slow->next;
		slow->next = fast->next;
		delete fast;
		return head;
    }
};