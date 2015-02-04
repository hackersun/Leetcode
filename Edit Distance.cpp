//dp
class Solution {
public:
	int minDistance(string word1, string word2) {
		int n1 = word1.size();
		int n2 = word2.size();
		if (n1 == 0) return n2;
		if (n2 == 0) return n1;

		vector<vector<int>> matrix(n1 + 1, vector<int>(n2 + 1));
		for (int i = 0; i <= n1; i++)
			matrix[i][0] = i;
		for (int j = 0; j <= n2; j++)
			matrix[0][j] = j;

		for (int i = 1; i <= n1; i++)
			for (int j = 1; j <= n2; j++) {
				if (word1[i - 1] == word2[j - 1])
					matrix[i][j] = matrix[i - 1][j - 1];
				else
					matrix[i][j] =
					min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1])) + 1;
			}

		return matrix[n1][n2];
	}
};