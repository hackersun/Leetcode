class Solution {
public:
void combineHelper(int n, int index, int k, vector<int> &path, vector<vector<int>> &res)
{
	if(path.size() == k){res.push_back(path); return;}
	for(int i = index + 1; i <= n; i++)
	{
		path.push_back(i);
		combineHelper(n, i, k, path, res);
		path.pop_back();
	}
}
vector<vector<int> > combine(int n, int k) {
		vector<vector<int>> res;
        if(n < k || n < 1 || k < 1) return res;
		vector<int> path;
		for(int i = 1; i <= n-k+1; i++)
		{
			path.push_back(i);
			combineHelper(n, i, k, path, res);
			path.pop_back();
		}
		return res;
    }
};