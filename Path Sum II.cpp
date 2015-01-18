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
void dfs(vector<vector<int>> &res, vector<int> &path, int cursum, TreeNode* root, int sum)
{
	//if(cursum + root->val > sum) return;
	path.push_back(root->val);
	cursum += root->val;

	if(root->left == NULL && root->right == NULL){
		if(cursum == sum) 
			res.push_back(path);
		path.pop_back();
		return;
	}

	if(root->left != NULL)
		dfs(res, path, cursum, root->left, sum);
	if(root->right != NULL)
		dfs(res, path,cursum, root->right, sum);
	
	path.pop_back();
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
		if(root == NULL) return res;
		vector<int> path;
		dfs(res, path, 0, root, sum);
		return res;
    }
};