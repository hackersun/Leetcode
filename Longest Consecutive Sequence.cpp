class Solution {
public:
    int longestConsecutive(vector<int> &num) {
		set<int> st;
		for(int i = 0; i < num.size(); i++)
			st.insert(num[i]);
		set<int>::iterator it = st.begin();
		int maxlen = 1;
		int curlen = 1;
		int tmpnum = *it;
		for(it++; it != st.end(); it++)
		{
			if(*it == ++tmpnum){
				curlen++;
			}else{
				maxlen = maxlen > curlen ? maxlen : curlen;
				tmpnum = *it;
				curlen = 1;
			}
		}
		if(curlen > maxlen) maxlen = curlen;

		return maxlen;
    }
};