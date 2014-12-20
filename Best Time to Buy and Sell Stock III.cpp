class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int sz = prices.size();
		if(sz < 2)return 0;
		int* profit = new int[sz];//max profit of 0..i
		int maxp = 0, min = 0;
		for(int i = 0; i < sz; i++)
		{
			if(prices[min] > prices[i]) min = i;
			int diff = prices[i] - prices[min];
			maxp = diff > maxp ? diff : maxp;
			profit[i] = maxp;
		}
		
		int res = 0;
		maxp = 0;
		int max = sz-1;
		for(int i = sz - 1; i >= 0; i--)
		{
			if(prices[max] < prices[i]) max = i;
			int diff = prices[max] - prices[i];
			maxp = diff > maxp ? diff : maxp;
			res = res > (maxp + profit[i]) ? res : (maxp + profit[i]);
		}
		return res;
    }
};