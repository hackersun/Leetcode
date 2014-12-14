class Solution {//Version 1
public:
    int reverse(int x) {
        if(x < 10 && x > -10) return x;
		bool isPositive = true;
		if(x < 0) {isPositive = false; x = 0 - x;}
		long long res = 0;
		while(x)
		{
			res = res *10 + x%10;
			x /= 10;
		}
		if(!isPositive) res = 0 - res;
		if(res < INT_MIN || res > INT_MAX)
			return 0;
		else
			return res;
    }
};

class Solution {//Version 2
public:
    int reverse(int x) {
		long long res = 0;
		while(x)
		{
			res = res *10 + x%10;
			x /= 10;
		}
		if(res < INT_MIN || res > INT_MAX)
			return 0;
		else
			return res;
    }
};
