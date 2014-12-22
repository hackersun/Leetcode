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
    ListNode *detectCycle(ListNode *head) {
        ListNode* pfast = head;
		ListNode* pslow = head;
		do{
			if(pfast) pfast = pfast->next;
			if(pfast) pfast = pfast->next;
			if(!pfast) return NULL;
			pslow = pslow->next;
		}while(pfast != pslow);
		pfast = head;
		while(pfast != pslow)
		{
			pfast = pfast->next;
			pslow = pslow->next;
		}
		return pfast;
    }
};