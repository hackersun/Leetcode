class Solution {
public:
    int removeDuplicates(int A[], int n) {
		if(n < 1)return n;
		int p = 0, q = 1;
		while(q < n)
		{
			if(A[q] != A[p]) A[++p] = A[q++];
			else q++;
		}
		return p+1;
    }
};