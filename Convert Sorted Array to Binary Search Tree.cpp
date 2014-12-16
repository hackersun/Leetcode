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
    TreeNode *sortedArrayToBSTHelper(vector<int> &num, int begin, int end)
{
	if(begin > end) return NULL;
	if(begin == end)
	{
		TreeNode* root = new TreeNode(num[begin]);
		return root;
	}
	int mid = (end - begin)/2 + begin;
	TreeNode* root = new TreeNode(num[mid]);
	root->left = sortedArrayToBSTHelper(num, begin, mid-1);
	root->right = sortedArrayToBSTHelper(num, mid+1, end);
	return root;
}
TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBSTHelper(num, 0, num.size()-1);
    }
};