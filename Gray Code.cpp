class Solution {
public:
    vector<int> grayCode(int n) {//Version 1
        vector<int> vec;
		if(n < 0) return vec;
		vec.push_back(0);
		for(int i = 1; i <= n; i++)
		{
			int size = vec.size();
			int j = size -1;
			while(j>=0) vec.push_back(vec[j--] + size);
		}
		return vec;
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {//Version 2
        vector<int> vec;
		if(n < 0) return vec;
		vec.push_back(0);
		while(n--)
		{
			int size = vec.size();
			int j = size -1;
			while(j>=0) vec.push_back(vec[j--] | size);
		}
		return vec;
    }
};