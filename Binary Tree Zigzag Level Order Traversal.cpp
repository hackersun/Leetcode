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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > res;
		if (root == NULL)return res;
		vector<int> level;
		vector<TreeNode*> path;
		path.push_back(root);
		int count = 1;
		while (!path.empty()) {
			TreeNode* tmp = *(path.begin());
			level.push_back(tmp->val);
			if (tmp->left)
				path.push_back(tmp->left);
			if (tmp->right)
				path.push_back(tmp->right);
			path.erase(path.begin());
			count--;
			if (count == 0) {
				res.push_back(level);
				count = path.size();
				level.clear();
			}
		}
		for (int i = 0; i < res.size(); i++) {
			if (i % 2)
				reverse(res[i].begin(), res[i].end());
		}
		return res;
	}
};