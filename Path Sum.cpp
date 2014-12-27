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
    bool hasPathSumHelper(TreeNode* root, int sum, int currentSum)
{
	currentSum += root->val;

	if(root->left == NULL && root->right == NULL)
		return currentSum == sum;
	else if(root->left == NULL && root->right != NULL)
		return hasPathSumHelper(root->right, sum, currentSum);
	else if(root->left != NULL && root->right == NULL)
		return hasPathSumHelper(root->left, sum, currentSum);
	else
		return hasPathSumHelper(root->left, sum, currentSum)
		|| hasPathSumHelper(root->right, sum, currentSum);
}
bool hasPathSum(TreeNode *root, int sum) {//recursive
		if(root == NULL) return false;
		return hasPathSumHelper(root, sum, 0);
    }
};

//deep first search