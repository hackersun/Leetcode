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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL) return head;
		ListNode* pNode = head;
		ListNode* pTmp = NULL;
		while(pNode->next)
		{
			pTmp = pNode->next;
			if(pTmp->val == pNode->val)
			{
				pNode->next = pTmp->next;
				delete pTmp;
			}
			else
				pNode = pNode->next;
		}
		return head;
    }
};