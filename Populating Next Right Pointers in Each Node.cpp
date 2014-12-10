/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
void connectHelper(TreeLinkNode *root)
{
	if(root == NULL) return;
	if(root->left != NULL)
		root->left->next = root->right;
	if(root->right != NULL)
		if(root->next == NULL) root->right->next = NULL;
		else root->right->next = root->next->left;
	connectHelper(root->left);
	connectHelper(root->right);
}
void connect(TreeLinkNode *root) 
{
	if(root)
	{
		root->next = NULL;
		connectHelper(root);
	}
}
};