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
void inorderTraversalHelper(TreeNode *root, vector<int> &path)
{
	if(root)
	{
		inorderTraversalHelper(root->left, path);
		path.push_back(root->val);
		inorderTraversalHelper(root->right, path);
	}
}

vector<int> inorderTraversal(TreeNode *root) //Version 1, Recursive
{
	vector<int> path;
	inorderTraversalHelper(root, path);
	return path;
}
};