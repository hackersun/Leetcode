class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		string res = "";
		if (numerator == 0) return "0";
		if (denominator == 0)return res;

		long long n = numerator;
		long long d = denominator;
		if ((n < 0 && d > 0) || (n > 0 && d < 0))
			res = "-";
		if (n < 0) n = -n;
		if (d < 0) d = -d;
		res += to_string(n / d);
		n = n%d;
		if (n == 0) return res;
		res += '.';

		int pos = res.size();
		map<long long, int> record;
		while (n != 0) {
			if (record.find(n) != record.end()) {
				res.insert(res.begin() + record[n], '(');
				res += ')';
				return res;
			}
			record[n] = pos;
			res += char(n * 10 / d + '0');
			pos++;
			n = (n * 10) % d;
		}
		return res;
	}
};