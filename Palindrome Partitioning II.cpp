class Solution {
public:
	int minCut(string s) {
		if (s.size() < 2) return 0;

		//s[i..j] is palindrome or not
		vector<vector<bool> > matrix(s.size(), vector<bool>(s.size(), false));
		for (int i = s.size() - 1; i < s.size(); i--)
			for (int j = i; j < s.size(); j++) {
				if (s[i] == s[j] && (j - i < 2 || matrix[i + 1][j - 1]))
					matrix[i][j] = true;
			}

		//dp
		vector<int> res(s.size(), 0);
		for (int i = 0; i < s.size(); i++) {
			if (matrix[0][i] == true)
				res[i] = 0;
			else {
				int mincut = INT_MAX;
				for (int j = 0; j < i; j++)
					if (matrix[j + 1][i] == true)
						mincut = min(mincut, res[j] + 1);
				res[i] = mincut;
			}
		}
		return res[s.size() - 1];
	}
};