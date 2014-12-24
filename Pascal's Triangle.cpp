class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> res;
		if(numRows < 1)return res;
		vector<int> tmp;
		tmp.push_back(1);
		res.push_back(tmp);
		while(--numRows)
		{
			vector<int> nextrow;
			nextrow.push_back(1);
			for(int i = 0; i < tmp.size()-1; i++)
				nextrow.push_back(tmp[i] + tmp[i+1]);
			nextrow.push_back(1);
			res.push_back(nextrow);
			tmp.swap(nextrow);
		}
		return res;
    }
};