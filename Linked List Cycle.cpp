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
    bool hasCycle(ListNode *head) {//Version 1.0
        if(!head) return false;
		ListNode* first = head;
		ListNode* second = head;
		while(first)
		{
			if(first->next && first->next->next)
			{
				first = first->next->next;
				second = second->next;
			}else
				return false;
			if(first == second)
				return true;
		}
		return false;
    }
};
bool hasCycle(ListNode *head) {//Version 2.0
		ListNode* first = head;
		ListNode* second = head;
		while(first)
		{
			if(first)
				first = first->next;
			if(first)
				first = first->next;
			if(!first)
				return false;
			second = second->next;
			if(first == second)
				return true;
		}
		return false;
    }
	
	bool hasCycle(ListNode *head) {//Version 3.0
        ListNode* pfast = head;
		ListNode* pslow = head;
		do{
			if(pfast!=NULL)
				pfast=pfast->next;
			if(pfast!=NULL)
				pfast=pfast->next;
			if(pfast==NULL)
				return false;
			pslow = pslow->next;
		}while(pfast != pslow);
		return true;
    }