int maxSubArray(int A[], int n) {//dp
        int max = A[0];
		int currentSum = max;
		for(int i = 1; i < n; i++)
		{
			if(currentSum < 0) currentSum = 0;
			currentSum += A[i];
			if(currentSum > max) max = currentSum;
		}
		return max;
    }

//====divide and conquer====
int divideAndConquer(int A[], int begin, int end)
{
	if(begin == end) return A[begin];
	int mid = (end - begin)/2 + begin;
	int left = divideAndConquer(A, begin, mid);
	int right = divideAndConquer(A, mid+1, end);

	int lefthalf = A[mid];
	int tmp = lefthalf;
	for(int i = mid-1; i >= begin; i--)
	{
		tmp += A[i];
		if(tmp > lefthalf) lefthalf = tmp;
	}
	int righthalf = A[mid+1];
	tmp = righthalf;
	for(int i = mid +2; i <= end; i++)
	{
		tmp += A[i];
		if(tmp > righthalf) righthalf = tmp;
	}
	int middle = lefthalf + righthalf;
	int res = left > right ? left : right;
	res = res > middle ? res : middle;
	return res;
}

int maxSubArray(int A[], int n) {//divide and conquer
        return divideAndConquer(A, 0, n-1);
    }