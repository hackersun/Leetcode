class Solution {
public:

vector<vector<int>> res;
vector<int> path;

void combinationSumHelper(vector<int> candidates, int sum ,int index, int target)
{
	if(sum > target) return;
	if(sum == target) {res.push_back(path); return;}
	for(int i = index; i < candidates.size(); i++)
	{
		path.push_back(candidates[i]);
		combinationSumHelper(candidates, sum+candidates[i], i, target);
		path.pop_back();
	}
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		res.clear();
		path.clear();
        combinationSumHelper(candidates, 0, 0, target);
		return res;
    }
};