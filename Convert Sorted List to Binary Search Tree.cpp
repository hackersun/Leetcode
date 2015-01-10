/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
ListNode* findmid(ListNode* head, ListNode* tail)
{
	ListNode* pfast = head;
	ListNode* pslow = head;
	while(pfast->next != tail)
	{
		if(pfast->next != tail) pfast = pfast->next; else break;
		if(pfast->next != tail) pfast = pfast->next; else break;
		pslow = pslow->next;
	}
	return pslow;
}

TreeNode* sortedListToBSTHelper(ListNode* head, ListNode* tail)
{
	if(head == tail) return NULL;
	ListNode* mid = findmid(head, tail);
	TreeNode* root = new TreeNode(mid->val);
	root->left = sortedListToBSTHelper(head, mid);
	root->right = sortedListToBSTHelper(mid->next, tail);
	return root;
}

TreeNode *sortedListToBST(ListNode *head) {
		if(head == NULL) return NULL;
		return sortedListToBSTHelper(head, NULL);
    }
};