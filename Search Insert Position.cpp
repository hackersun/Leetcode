class Solution {
public:
	int searchInsert1(int A[], int n, int target) {//method 1: sequence search
        if(A==NULL)return 0;
		int i = 0;
		for(; i < n; i++)
			if(target <= A[i]) break;
		return i;
    }

    int binSearch(int arr[], int begin, int end, int target)
	{
		int mid = begin + (end-begin)/2;
		if(arr[mid] == target) return mid;
		else if(arr[mid] < target) 
		{
			if(begin == end) return end;
			else if(arr[mid+1] >= target) return mid+1;
			else return binSearch(arr, mid+1, end, target);
		}
		else
		{
			if(mid == 0) return 0;
			else return binSearch(arr, begin, mid, target);
		}
	}
	int searchInsert(int A[], int n, int target) {//method 2: binsearch version
        if(A==NULL)return 0;
		return binSearch(A, 0, n, target);
    }
};