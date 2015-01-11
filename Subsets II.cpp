void findsubset(vector<int> vec, int index, vector<int> &path, vector<vector<int>> &res)
	{
		res.push_back(path);
		for(int i = index; i < vec.size(); i++)
		{
			if(i != index && vec[i] == vec[i-1])continue;
			path.push_back(vec[i]);
			findsubset(vec, i+1, path, res);
			path.pop_back();
		}
	}

	vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> res;
		sort(S.begin(), S.end());
		vector<int> path;
		findsubset(S, 0, path, res);
		return res;
    }