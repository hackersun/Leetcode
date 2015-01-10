class Solution {
public:
string deletezero(string str)
{
	if(str.length() < 2) return str;
	int i = 0;
	while(i < str.length() && str[i] == '0')
		i++;
	if(i == str.length())
		return "0";
	return string(str, i);

}

int compareVersion(string version1, string version2) {
        if(version1 == version2) return 0;
		int dot1 = 0, dot2 = 0;
		while(dot1 < version1.size() && version1[dot1] != '.')
			dot1++;
		while(dot2 < version2.size() && version2[dot2] != '.')
			dot2++;
		string sv1 = deletezero(string(version1, 0, dot1));
		string sv2 = deletezero(string(version2, 0, dot2));
		if(sv1.length() != sv2.length())
			return sv1.length() > sv2.length() ? 1 : -1;
		else if(sv1 != sv2)
			return sv1 > sv2 ? 1 : -1;
		else{//sv1 == sv2, cpmpare what behaind dot
			string zerodot = (".0");
			if(dot1 == version1.length() && dot2 == version2.length())
				return 0;
			else if(dot1 != version1.length() && dot2 == version2.length()){
				string tmp = string(version1, dot1+1);
				if(tmp.find_first_not_of(zerodot) == string::npos)return 0;
				else return 1;
			}else if(dot1 == version1.length() && dot2 != version2.length()){
				string tmp = string(version2, dot2+1);
				if(tmp.find_first_not_of(zerodot) == string::npos)return 0;
				else return -1;
			}
			sv1 = string(version1, dot1+1);
			sv2 = string(version2, dot2+1);
			return compareVersion(sv1, sv2);
		}
    }
};