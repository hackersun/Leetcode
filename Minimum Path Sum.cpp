class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int row = grid.size();
		int col = grid[0].size();
		int** dp = new int*[row];
		for(int i = 0; i < row; i++)
			dp[i] = new int[col];

		dp[0][0] = grid[0][0];
		for(int j = 1; j < col; j++)
			dp[0][j] = dp[0][j-1] + grid[0][j];


		for(int i = 1; i < row; i++)
			dp[i][0] = dp[i-1][0] + grid[i][0];

		for(int i = 1; i < row; i++)
			for(int j = 1; j < col; j++)
			{
				int tmp = dp[i][j-1] < dp[i-1][j] ? dp[i][j-1] : dp[i-1][j];
				dp[i][j] = tmp + grid[i][j];
			}

		int res = dp[row-1][col-1];

		for(int i = 0; i < row; i++)
			delete dp[i];
		delete[] dp;
		return res;
    }
};


class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int row = grid.size();
		int col = grid[0].size();

		for(int j = 1; j < col; j++)
			grid[0][j] += grid[0][j-1];
		for(int i = 1; i < row; i++)
			grid[i][0] += grid[i-1][0];

		for(int i = 1; i < row; i++)
			for(int j = 1; j < col; j++)
			{
				int tmp = grid[i-1][j] < grid[i][j-1] ? grid[i-1][j] : grid[i][j-1];
				grid[i][j] += tmp;
			}
		return grid[row-1][col-1];
    }
};