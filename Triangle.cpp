class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int rows = triangle.size();
		int cols = triangle[rows - 1].size();

		int** matrix = new int*[rows];
		for (int i = 0; i < rows; i++)
			matrix[i] = new int[cols];

		matrix[0][0] = triangle[0][0];
		for (int i = 1; i < rows; i++)
			for (int j = 0; j <= i; j++) {
				if (j == 0)
					matrix[i][0] = matrix[i - 1][0] + triangle[i][0];
				else if (j == i)
					matrix[i][j] = matrix[i - 1][i - 1] + triangle[i][j];
				else
					matrix[i][j] = min(matrix[i - 1][j - 1], matrix[i - 1][j]) + triangle[i][j];
			}
		int min = matrix[rows - 1][0];
		for (int i = 0; i < rows; i++)
			if (matrix[rows - 1][i] < min)
				min = matrix[rows - 1][i];

		for (int i = 0; i < rows; i++)
			delete[] matrix[i];
		delete matrix;

		return min;
	}
};