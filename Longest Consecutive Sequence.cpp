class Solution {//method 1, sort
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

class Solution {//method 2, O(n)
public:
    int longestConsecutive(vector<int> &num) {
		map<int, int> nums;
		map<int, int> visited;
		for(int i = 0; i < num.size(); i++)
			nums[num[i]] = 1;
		int maxlen = 1;
		for(int i = 0; i < num.size(); i++)
		{
			if(visited[num[i]] == 1) continue;
			bool isup = true, isdown = true;
			int up_i = num[i], down_i = num[i];
			while(isup || isdown)
			{
				if(isup){
					if(nums[up_i+1] == 1)
						visited[++up_i] = 1;
					else
						isup = false;
				}
				if(isdown){
					if(nums[down_i-1] == 1)
						visited[--down_i] = 1;
					else
						isdown = false;
				}
			}
			int tmp = up_i - down_i + 1;
			if(tmp > maxlen) maxlen = tmp;
		}
		return maxlen;
    }
};