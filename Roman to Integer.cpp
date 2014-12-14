class Solution {
public:
int romanToInt(string s) {
	int length = s.length();
	if(length < 1) return 0;
	map<char,int> m;
	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;
	int i = length - 1;
	int res = m[s[i--]];
	while(i >= 0)
	{
		if(m[s[i+1]] > m[s[i]])
			res -= m[s[i]];
		else 
			res += m[s[i]];
		i--;
	}
	return res;
}
};
