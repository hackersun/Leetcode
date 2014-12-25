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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> floor;
		if(root == NULL)return floor;

		stack<vector<int>> res;
		vector<int> row;
		row.push_back(root->val);
		res.push(row);

		deque<TreeNode*> tque;
		tque.push_back(root);
		int count = 1;
		while(!tque.empty())
		{
			if(tque.front()->left) tque.push_back(tque.front()->left);
			if(tque.front()->right) tque.push_back(tque.front()->right);
			tque.pop_front();
			count--;
			if(count == 0)
			{
				count = tque.size();
				row.clear();
				deque<TreeNode*>::iterator it = tque.begin();
				for(; it != tque.end(); it++)
					row.push_back((*it)->val);
				if(row.size() > 0)
					res.push(row);
			}
		}
		while(!res.empty()){
			row = res.top();
			floor.push_back(row);
			res.pop();
		}

		return floor;
    }
};