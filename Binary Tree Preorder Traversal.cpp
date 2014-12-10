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
void preorderTraversalHelper(TreeNode *root, vector<int> &path) {
	if(root) 
	{
		path.push_back(root->val);
		if(root->left) preorderTraversalHelper(root->left, path);
		if(root->right) preorderTraversalHelper(root->right, path);
	}
}
vector<int> preorderTraversal(TreeNode *root) {//Version 1.0, Recursion
        vector<int> path;
		preorderTraversalHelper(root, path);
		return path;
    }
};

