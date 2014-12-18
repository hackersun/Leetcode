class Solution {
public:
    void backTracking(vector<string> &res, string str, int left, int right, int n)
{
	if(left < right || right + left > n*2) return;
	if(left == n && right == n) { res.push_back(str); return; }
	backTracking(res, str + "(", left + 1, right, n);
	backTracking(res, str + ")", left, right + 1, n);
}

vector<string> generateParenthesis(int n) {
        vector<string> res;
		string str = "";
		backTracking(res, str, 0, 0, n);
		return res;
    }
};