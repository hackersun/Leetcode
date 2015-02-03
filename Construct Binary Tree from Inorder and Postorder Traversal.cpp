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
	TreeNode* buildTreeHelper(vector<int> &inorder, int begin1, int end1,
		vector<int> &postorder, int begin2, int end2) {
		if (begin1 > end1) return NULL;
		if (begin1 == end1) return new TreeNode(inorder[begin1]);

		TreeNode* root = new TreeNode(postorder[end2]);
		int mid = end1;
		while (inorder[mid] != postorder[end2]) mid--;

		root->left = buildTreeHelper(inorder, begin1, mid - 1,
			postorder, begin2, begin2 + mid - begin1 - 1);
		root->right = buildTreeHelper(inorder, mid + 1, end1,
			postorder, end2 - end1 + mid, end2 - 1);
		return root;
	}

	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return buildTreeHelper(inorder, 0, inorder.size() - 1,
			postorder, 0, postorder.size() - 1);
	}
};