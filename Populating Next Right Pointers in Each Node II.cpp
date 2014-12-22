/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    TreeLinkNode* rightNeighbor(TreeLinkNode* left)
{
	if(left->next == NULL) return NULL;
	else if(left->next->left)
		return left->next->left;
	else if(left->next->right)
		return left->next->right;
	else return rightNeighbor(left->next);
}

void connectHelper(TreeLinkNode* root)
{
	if(root)
	{
		if(root->right)
			root->right->next = rightNeighbor(root);
		if(root->left)
		{
			if(root->right)
				root->left->next = root->right;
			else
				root->left->next = rightNeighbor(root);
		}
		connectHelper(root->right);
		connectHelper(root->left);
	}
}

void connect(TreeLinkNode *root) {//method 1: recursive
        if(root)
		{
			root->next = NULL;
			if(root->right)
				root->right->next = NULL;
			if(root->left)
			{
				if(root->right) 
					root->left->next = root->right;
				else
					root->left->next = NULL;
			}
			connectHelper(root->right);
			connectHelper(root->left);
		}
    }
};

void connect(TreeLinkNode *root) {//method 2: bfs
        if(root == NULL) return;
		vector<TreeLinkNode*> vec;
		vec.push_back(root);
		int count = 1;
		while(!vec.empty())
		{
			if(count > 1) vec[0]->next = vec[1];
			else
				vec[0]->next = NULL;
			if(vec[0]->left) vec.push_back(vec[0]->left);
			if(vec[0]->right) vec.push_back(vec[0]->right);
			vec.erase(vec.begin());
			count--;

			if(count == 0)
				count = vec.size();
		}
    }

