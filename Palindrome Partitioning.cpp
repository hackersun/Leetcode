class Solution {
public:
	bool isPalindrome(string str, int begin, int end) {
		while (begin < end)
			if (str[begin] == str[end]) {
				begin++;
				end--;
			}
			else
				return false;
		return true;
	}

	void partitionHelper(string &s, int begin, vector<string> &path, vector<vector<string>> &res) {
		if (begin >= s.size()) {
			res.push_back(path);
			return;
		}
		for (int i = begin; i < s.size(); i++) {
			if (isPalindrome(s, begin, i)) {
				path.push_back(string(s, begin, i - begin + 1));
				partitionHelper(s, i + 1, path, res);
				path.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> path;
		partitionHelper(s, 0, path, res);
		return res;
	}
};