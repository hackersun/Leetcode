class Solution {
public:
	double pow(double x, int n) {
		if (n == 0) return 1;
		else if (n == 1) return x;
		if (x > -0.000001 && x < 0.000001) return 0;
		if (n < 0) { x = 1.0 / x; n = -n; }
		double res = pow(x, n >> 1);
		if (n & 1)
			return res*res*x;
		else
			return res*res;
	}
};