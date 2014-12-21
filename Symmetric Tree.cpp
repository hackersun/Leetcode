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
    bool isSymmetricHelper(TreeNode* left, TreeNode* right)
{
	if(left==NULL &&  right==NULL) return true;
	else if(left==NULL ||  right==NULL) return false;
	if(left->val == right->val)
		return isSymmetricHelper(left->left, right->right) 
		&& isSymmetricHelper(left->right, right->left);
	return false;
}
bool isSymmetric(TreeNode *root) {
        if(root == NULL) return true;
		return isSymmetricHelper(root->left, root->right);
    }
};