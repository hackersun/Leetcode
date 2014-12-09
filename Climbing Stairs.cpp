#include<iostream>
using namespace std;

/*
//Recursion
int climbStairs(int n) {
	if( n < 2 ) return 1;
	else return climbStairs(n-1) + climbStairs(n-2);
}
*/

//dp
int climbStairs(int n) {
	if( n < 2 ) return 1;
	int* dp = new int[n];
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i < n; i++)
		dp[i] = dp[i-1] + dp[i-2];
	int res = dp[n-1] + dp[n-2];
	delete[] dp;
	return res;
}

int main()
{
	cout<<climbStairs(2)<<endl;
	return 0;
}
