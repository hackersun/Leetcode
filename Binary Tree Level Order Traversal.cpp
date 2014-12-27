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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
		if(root == NULL)return res;

		vector<int> tmp;
		tmp.push_back(root->val);
		res.push_back(tmp);

		vector<TreeNode*> vec;
		vec.push_back(root);
		int count = 1;

		while(!vec.empty())
		{
			vector<TreeNode*>::iterator it = vec.begin();
			if(vec[0]->left != NULL) vec.push_back(vec[0]->left);
			if(vec[0]->right != NULL) vec.push_back(vec[0]->right);
			vec.erase(vec.begin());
			count--;
			if(count == 0 && vec.size() > 0)
			{
				tmp.clear();
				for(int i = 0; i < vec.size(); i++)
					tmp.push_back(vec[i]->val);
				res.push_back(tmp);
				count = vec.size();
			}
		}
		return res;
    }
};