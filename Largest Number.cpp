class Solution {
public:
	static bool cmp(string a, string b) {
		return a + b > b + a;
	}
	string largestNumber(vector<int> &num) {
		vector<string> snum;
		for (int i = 0; i < num.size(); i++)
			snum.push_back(to_string(num[i]));

		sort(snum.begin(), snum.end(), cmp);

		string res = "";
		for (int i = 0; i < snum.size(); i++)
			res += snum[i];

		if (res[0] == '0')
			return "0";
		return res;
	}
};