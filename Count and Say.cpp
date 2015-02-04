class Solution {
public:
	string toString(int num) {
		string res = "";
		while (num > 0) {
			char c = '0' + num % 10;
			res = c + res;
			num /= 10;
		}
		return res;
	}
	string countAndSay(int n) {
		string str = "1";
		for (int i = 1; i < n; i++) {
			string tmp = "";
			char c = str[0];
			int times = 1;
			for (int len = 1; len < str.length(); len++) {
				if (str[len] == c)
					times++;
				else {
					tmp = tmp + toString(times) + c;
					times = 1;
					c = str[len];
				}
			}
			tmp = tmp + toString(times) + c;
			str = tmp;
		}
		return str;
	}
};