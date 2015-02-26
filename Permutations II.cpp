class Solution {
public:
	void permute(vector<int> &num, int index, vector<vector<int>> &res)
	{
		if (index >= num.size()) { res.push_back(num); return; }
		set<int> swapnum;
		swapnum.insert(num[index]);
		for (int i = index; i < num.size(); i++)
		{
			if (index != i)
			{
				set<int>::iterator it = swapnum.find(num[i]);
				if (it != swapnum.end())
					continue;
				else
					swapnum.insert(num[i]);
			}
			swap(num[index], num[i]);
			permute(num, index + 1, res);
			swap(num[index], num[i]);
		}
	}
	vector<vector<int> > permuteUnique(vector<int> &num) {
		vector<vector<int>> res;
		permute(num, 0, res);
		return res;
	}
};