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
void sumHelper(TreeNode* root, int &sum, int tmp)
{
	tmp = tmp * 10 + root->val;
	if(root->left == NULL && root->right == NULL)
		sum += tmp;
	if(root->left != NULL)
		sumHelper(root->left, sum, tmp);
	if(root->right != NULL)
		sumHelper(root->right, sum, tmp);
}
int sumNumbers(TreeNode *root) {
        int sum = 0;
		if(root == NULL)return sum;
		sumHelper(root, sum, 0);
		return sum;
    }
};