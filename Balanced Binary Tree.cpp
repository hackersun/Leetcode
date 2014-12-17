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
    bool isBalancedHelper(TreeNode* root, int &height)
{
	if(root == NULL) 
	{
		height = 0;
		return true;
	}
	int lheight = 0;
	bool islbalanced = isBalancedHelper(root->left, lheight);
	if(islbalanced == false) return false;

	int rheight = 0;
	bool isrbalanced = isBalancedHelper(root->right, rheight);
	if(isrbalanced == false) return false;

	if(lheight - rheight > 1 || lheight - rheight < -1) return false;
	height = lheight > rheight ? lheight+1 : rheight+1;
	return true;
}
bool isBalanced(TreeNode *root) {
        int height = 0;
		return isBalancedHelper(root, height);
    }
};