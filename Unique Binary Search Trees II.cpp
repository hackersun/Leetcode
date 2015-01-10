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
vector<TreeNode*> generate(int left, int right)
{
	vector<TreeNode* > res;
	if(left > right)return res;
	if(left == right){
		res.push_back(new TreeNode(left));
		return res;
	}
	for(int it = left; it <= right; it++)
	{
		vector<TreeNode*> lchild;
		vector<TreeNode*> rchild;
		if(it == left)
		{
			rchild = generate(left+1, right);
			for(int i = 0; i < rchild.size(); i++)
			{
				TreeNode* root = new TreeNode(it);
				root->right = rchild[i];
				res.push_back(root);
			}
		}else if(it == right)
		{
			lchild = generate(left, right-1);
			for(int i = 0; i < lchild.size(); i++)
			{
				TreeNode* root = new TreeNode(it);
				root->left = lchild[i];
				res.push_back(root);
			}
		}else{
			lchild = generate(left, it-1);
			rchild = generate(it+1, right);
			for(int i = 0; i < lchild.size(); i++)
				for(int j = 0; j < rchild.size(); j++)
				{
					TreeNode* root = new TreeNode(it);
					root->left = lchild[i];
					root->right = rchild[j];
					res.push_back(root);
				}
		}
	}
	return res;
}

vector<TreeNode *> generateTrees(int n) {
		if(n < 1){
			vector<TreeNode*> res;
			TreeNode* tmp = NULL;
			res.push_back(tmp);
			return res;
		}
		return generate(1, n);
    }
};