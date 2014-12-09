class Solution {
public:
vector<int> num;
    int numTrees(int n) {
        num.push_back(1);
		num.push_back(1);
		if(n < num.size()) return num[n];
		int m = num.size();
		for(; m <= n; m++)
		{
			int res = 0;
			for(int i = 0; i <= m-1; i++)
				res += num[i]*num[m-1-i];
			num.push_back(res);
		}
		return num[n];
    }
};