class Solution {
public:
    int majorityElement(vector<int> &num) {//method 1, sort
        sort(num.begin(), num.end());
		return num[num.size()/2];
    }
};

class Solution {
public:
    int majorityElement(vector<int> &num) {//method 2
        map<int, int> mp;
		map<int, int>::iterator it;
		for(int i = 0; i < num.size(); i++)
		{
			it = mp.find(num[i]);
			if(it == mp.end())
				mp[num[i]] = 1;
			else
				it->second += 1;
		}
		int max = mp.begin()->first;
		int maxcount = mp.begin()->second;
		for(it = mp.begin(); it != mp.end(); it++)
		{
			if(it->second > maxcount)
			{
				maxcount = it->second;
				max = it->first;
			}
		}
		return max;
    }
};

class Solution {
public:
    int majorityElement(vector<int> &num) {//method 2 optimize
        map<int, int> mp;
		map<int, int>::iterator it;
		for(int i = 0; i < num.size(); i++)
		{
			it = mp.find(num[i]);
			if(it == mp.end()){
				mp[num[i]] = 1;
				if(1 > num.size()/2)
					return num[i];
			}
			else{
				it->second += 1;
				if(it->second > num.size()/2)
					return it->first;
			}
		}
    }
};