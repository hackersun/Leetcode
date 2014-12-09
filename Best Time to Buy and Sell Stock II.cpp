class Solution {
public:
    int maxProfit(vector<int> &prices) {
		if(prices.size() < 2) return 0;
		int maxprofit = 0;
		vector<int>::iterator it = prices.begin();
		int min = *it;
		for(it++; it != prices.end(); it++)
		{
			if(*it >= *(it-1))
				continue;
			else{
				maxprofit += *(it-1) - min;
				min = *it;
			}
		}
		return maxprofit + *(it-1) - min;
    }
};