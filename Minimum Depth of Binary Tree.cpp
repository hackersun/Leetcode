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
    int minDepth(TreeNode *root) {
		if(root == NULL)return 0;
		vector<TreeNode*> treelevel;
		treelevel.push_back(root);
		int depth = 1;
		int count = 1;
		while(!treelevel.empty())
		{
			if(treelevel[0]->left == NULL && treelevel[0]->right == NULL)
				return depth;
			if(treelevel[0]->left) treelevel.push_back(treelevel[0]->left);
			if(treelevel[0]->right) treelevel.push_back(treelevel[0]->right);
			treelevel.erase(treelevel.begin());
			count--;
			if(count == 0)
			{
				depth++;
				count = treelevel.size();
			}
		}
    }
};