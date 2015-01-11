class Solution {
public:
bool isValidSudoku(vector<vector<char> > &board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
		vector<vector<bool>> col(9, vector<bool>(9, false));
		vector<vector<bool>> block(9, vector<bool>(9, false));

		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++)
			{
				if(board[i][j] == '.') continue;
				int num = board[i][j] - '1';
				if(row[i][num] || col[j][num] || block[i/3*3 + j/3][num])
					return false;
				row[i][num] = col[j][num] = block[i/3*3 + j/3][num] = true;
			}
		return true;
    }
};