class Solution {
public:
void subsetsHelper(vector<int> &S, int i, vector<int> &path, vector<vector<int> > &res)
{
	if(i == S.size()){ res.push_back(path); return; }
	subsetsHelper(S, i+1, path, res);
	path.push_back(S[i]);
	subsetsHelper(S, i+1, path, res);
	path.pop_back();
}

vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
		vector<int> path;
		sort(S.begin(), S.end());
		subsetsHelper(S, 0, path, res);
		return res;
    }
};