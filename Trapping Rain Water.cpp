class Solution {
public:
    int trap(int A[], int n) {
        if(A == NULL || n < 1) return 0;
		int max = 0;
		vector<int> leftMostHeight(n, 0);
		for(int i = 0; i < n; i++)
		{
			leftMostHeight[i] = max;
			max = max > A[i] ? max : A[i];
		}
		max = 0;
		vector<int> rightMostHeight(n, 0);
		for(int i = n-1; i >= 0; i--)
		{
			rightMostHeight[i] = max;
			max = max > A[i] ? max : A[i];
		}
		int water = 0;
		for(int i = 0; i < n; i++)
		{
			int trapped = min(leftMostHeight[i], rightMostHeight[i]) - A[i];
			if(trapped > 0)
				water += trapped;
		}
		return water;
    }
};