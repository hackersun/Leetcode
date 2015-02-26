class Solution {
public:
	string addBinary(string a, string b) {
		int len = max(a.size(), b.size()) + 1;
		a = string(len - a.size(), '0') + a;
		b = string(len - b.size(), '0') + b;
		string res = string(len, '0');

		int carry = 0;
		for (int i = len - 1; i >= 0; i--) {
			int sum = (a[i] - '0') + (b[i] - '0') + carry;
			res[i] = '0' + (sum % 2);
			carry = (sum > 1 ? 1 : 0);
		}
		if (res[0] == '0')
			return string(res, 1);
		else return res;
	}
};