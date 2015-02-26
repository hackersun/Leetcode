class Solution {
public:
	void nextPermutation(vector<int> &num) {
		if (num.size() < 1) return;
		int i = num.size() - 1;
		while (i > 0 && num[i - 1] >= num[i])
			i--;

		if (i == 0)
			sort(num.begin(), num.end());
		else {
			int n = i;
			for (int j = i; j < num.size(); j++)
				if (num[j] > num[i - 1] && num[j] < num[n])
					n = j;
			swap(num[i - 1], num[n]);
			sort(num.begin() + i, num.end());
		}
	}
};