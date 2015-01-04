class Solution {
public:
    int search(int A[], int n, int target) {
        if(A == NULL || n < 1) return -1;
		int begin = 0, end = n-1;
		int mid = 0;
		while(begin <= end)
		{
			mid = begin + (end - begin)/2;
			if(A[mid] == target) return mid;
			if(A[begin] <= A[mid]){
				if(A[begin] <= target && target < A[mid])
					end = mid - 1;
				else
					begin = mid + 1;
			}else{
				if(A[mid] < target && target <= A[end])
					begin = mid + 1;
				else
					end = mid - 1;
			}
		}
		return -1;
    }
};