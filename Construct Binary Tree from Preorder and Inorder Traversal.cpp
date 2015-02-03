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
	TreeNode* buildTreeHelper(vector<int> &preorder, int begin1, int end1,
		vector<int> &inorder, int begin2, int end2) {
		if (begin1 > end1) return NULL;
		if (begin1 == end1) return new TreeNode(preorder[begin1]);

		TreeNode* root = new TreeNode(preorder[begin1]);
		int mid = begin2;
		while (inorder[mid] != preorder[begin1]) mid++;

		root->left = buildTreeHelper(preorder, begin1 + 1, begin1 + (mid - begin2),
			inorder, begin2, mid - 1);
		root->right = buildTreeHelper(preorder, begin1 + (mid - begin2) + 1, end1,
			inorder, mid + 1, end2);
		return root;
	}
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
};