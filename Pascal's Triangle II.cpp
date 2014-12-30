class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
		int i = 0;
		for(; i <= rowIndex && i < 2; i++)
			res.push_back(1);
		if(i > rowIndex) return res;
		vector<int> tmp;
		for(i = 2; i <= rowIndex; i++)
		{
			tmp.clear();
			tmp.push_back(1);
			for(int j = 0; j < res.size()-1; j++)
				tmp.push_back(res[j]+res[j+1]);
			tmp.push_back(1);
			res.assign(tmp.begin(), tmp.end());
		}
		return res;
    }
};