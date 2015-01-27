//int commonPrefix(string str1, string str2) {
//	int len = 0;
//	while (len < str1.size() && len < str2.size() && str1[len] == str2[len])
//		len++;
//	return len;
//}
//string longestCommonPrefix(vector<string> &strs) {
//	if (strs.size() < 1) return "";
//	else if (strs.size() == 1) return strs[0];
//	sort(strs.begin(), strs.end());
//	int index = 0;
//	int maxlen = 0;
//	for (int i = 0; i < strs.size() - 1; i++)
//	{
//		int tmplen = commonPrefix(strs[i], strs[i + 1]);
//		if (tmplen > maxlen) {
//			maxlen = tmplen;
//			index = i;
//		}
//	}
//	return string(strs[index], 0, maxlen);
//}

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		if (strs.size() < 1) return "";
		int len = 0;
		while (true) {
			char tmp = strs[0][len];
			bool isSame = true;
			for (int i = 0; i < strs.size(); i++) {
				if (len == strs[i].size()) return strs[i];
				if (strs[i][len] != tmp) return string(strs[0], 0, len);
			}
			len++;
		}
	}
};