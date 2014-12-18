class Solution {
public:
void permuteHelper(vector<int> num, int i, vector<vector<int>> &res)
{
	int sz = num.size();
	if(i == sz-1) {res.push_back(num); return;}
	for(int j = i; j < sz; j++)
	{
		swap(num[i], num[j]);
		permuteHelper(num, i+1, res);
	}
}

vector<vector<int>> permute(vector<int> &num) {
        vector<vector<int>> res;
		permuteHelper(num, 0, res);
		return res;
    }
};