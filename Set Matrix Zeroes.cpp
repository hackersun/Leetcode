class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {//Space:O(m + n)
        vector<int> row(matrix.size(), 1);
		vector<int> col(matrix[0].size(), 1);
		for(int i = 0; i < matrix.size(); i++)
			for(int j = 0; j < matrix[0].size(); j++)
			{
				if(matrix[i][j] == 0)
				{
					row[i] = 0;
					col[j] = 0;
				}
			}
		for(int i = 0; i < row.size(); i++)
			if(row[i] == 0)
				for(int j = 0; j < matrix[0].size(); j++)
					matrix[i][j] = 0;
		for(int j = 0; j < col.size(); j++)
			if(col[j] == 0)
				for(int i = 0; i < matrix.size(); i++)
					matrix[i][j] = 0;
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {//Space:O(1)
		bool firstRowZero = false;
		bool firstColZero = false;

		for(int i = 0; i < matrix.size(); i++)
			if(matrix[i][0] == 0)
				firstColZero = true;

		for(int j = 0; j < matrix[0].size(); j++)
			if(matrix[0][j] == 0)
				firstRowZero = true;

		for(int i = 1; i < matrix.size(); i++)
			for(int j = 1; j < matrix[0].size(); j++)
			{
				if(matrix[i][j] == 0)
				{
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}

		for(int i = 1; i < matrix.size(); i++)
			if(matrix[i][0] == 0)
				for(int j = 1; j < matrix[0].size(); j++)
					matrix[i][j] = 0;

		for(int j = 1; j < matrix[0].size(); j++)
			if(matrix[0][j] == 0)
				for(int i = 1; i < matrix.size(); i++)
					matrix[i][j] = 0;

		if(firstColZero)
			for(int i = 0; i < matrix.size(); i++)
				matrix[i][0] = 0;

		if(firstRowZero)
			for(int j = 0; j < matrix[0].size(); j++)
				matrix[0][j] = 0;
    }
};