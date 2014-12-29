class Solution {
public:
    int titleToNumber(string s) {
        int colNum = 0;
		for(int i = 0; i < s.length(); i++)
			colNum = colNum * 26 + (s[i] - '@');
		return colNum;
    }
};