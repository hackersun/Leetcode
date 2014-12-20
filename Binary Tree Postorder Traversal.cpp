#include<iostream>
#include<map>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};

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
////====================================
int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(4);
	cout<<maxProfit(num)<<endl;
	return 0;
}

////====================================
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