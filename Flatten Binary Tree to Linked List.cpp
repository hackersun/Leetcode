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
void dfs(TreeNode* root, vector<TreeNode*> &vec)
{
	if(root != NULL)
	{
		vec.push_back(root);
		dfs(root->left, vec);
		dfs(root->right, vec);
	}
}

void flatten(TreeNode *root) {
		if(root == NULL) return;
        vector<TreeNode*> vec;
		dfs(root, vec);
		vector<TreeNode*>::iterator it = vec.begin();
		for(; it != vec.end() - 1; it++){
			(*it)->left = NULL;
			(*it)->right = *(it+1);
		}
		(*it)->left = NULL;
		(*it)->right = NULL;
		return;
    }
};