class Solution {
public:
    bool search(int A[], int n, int target) {
        int begin = 0;
		int end = n - 1;
		while(begin < end)
		{
			int mid = begin + (end - begin)/2;
			if(A[mid] == target) return true;
			else if(A[begin] == A[mid])
			{
				for(int i = begin; i < mid; i++)
					if(A[i] == target) return true;
				begin = mid+1;
			}
			else if(A[begin] < A[mid])//begin to mid increase
			{
				if(A[begin] <= target && target < A[mid])
					end = mid-1;
				else begin = mid + 1;
			}else//mid to end increase
			{
				if(A[mid] < target && target <= A[end])
					begin = mid + 1;
				else end = mid - 1;
			}
		}
		if(begin == end && A[begin] == target)
			return true;
		else
			return false;
    }
};