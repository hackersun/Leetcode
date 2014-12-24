class Solution {
public:
    int removeDuplicates(int A[], int n) {
		if(A==NULL) return 0;
		if(n < 3) return n;
        int tail = 0, front = 1;
		bool isRepeat = false;
		while(front < n)
		{
			if(A[tail] != A[front])
			{
				isRepeat = false;
				A[++tail] = A[front++];
			}else{//A[tail] == A[front]
				if(!isRepeat)
				{
					isRepeat = true;
					A[++tail] = A[front];
				}
				front++;
			}
		}
		return ++tail;
    }
};