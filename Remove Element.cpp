class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int index = 0;
		for(int p = 0; p < n; p++)
			if(A[p] != elem) A[index++] = A[p];
		return index;
    }
};