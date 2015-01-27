class Solution {
public:
void letterCombinationsHelper(string digits, int index, map<char, string> mp, vector<string> &res, string path)
{
	if (index >= digits.length()) {
		res.push_back(path);
		return;
	}
	string tmp = mp[digits[index]];
	if (tmp.size() > 0)
		for (int i = 0; i < tmp.size(); i++)
			letterCombinationsHelper(digits, index + 1, mp, res, path + tmp[i]);
	else
		letterCombinationsHelper(digits, index + 2, mp, res, path);
}

vector<string> letterCombinations(string digits) {
	vector<string> res;
	map<char, string> mp;
	mp['0'] = "";
	mp['1'] = "";
	mp['2'] = "abc";
	mp['3'] = "def";
	mp['4'] = "ghi";
	mp['5'] = "jkl";
	mp['6'] = "mno";
	mp['7'] = "pqrs";
	mp['8'] = "tuv";
	mp['9'] = "wxyz";

	string path = "";
	letterCombinationsHelper(digits, 0, mp, res, path);
	return res;
}
};