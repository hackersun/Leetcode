class Solution {
public:
    int singleNumber(int A[], int n) {
        map<int,int> mp;
		map<int,int>::iterator it;
		for(int i = 0; i < n; i++)
		{
			it = mp.find(A[i]);
			if(it == mp.end())
				mp[A[i]] = 1;
			else
				mp[A[i]]++;
		}
		for(it = mp.begin(); it != mp.end(); it++)
			if(it->second == 1) return it->first;
    }
};