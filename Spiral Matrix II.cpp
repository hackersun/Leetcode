class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
		vector<int> tmp(n, 0);
        vector<vector<int>> res;
		for(int i = 0; i < n; i++)
			res.push_back(tmp);
		int num = 1;
		for(int i = 0; i < (n+1)/2; i++)
		{
			for(int a = i; a <= n-1-i; a++)//up row
				res[i][a] = num++;

			for(int a = i+1; a <= n-1-i; a++)//right col
				res[a][n-1-i] = num++;

			for(int a = n-2-i; a >= i; a--)//bottem row
				res[n-1-i][a] = num++;

			for(int a = n-2-i; a > i; a--)//left col
				res[a][i] = num++;
		}
		return res;
    }
};