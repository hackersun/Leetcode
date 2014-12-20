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
void postorder(vector<int> &path, TreeNode* root)
{
	if(root)
	{
		postorder(path, root->left);
		postorder(path, root->right);
		path.push_back(root->val);
	}
}
vector<int> postorderTraversal(TreeNode *root) {
        vector<int> path;
		postorder(path, root);
		return path;
    }
};