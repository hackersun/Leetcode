class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
		vector<int> notFound;
		notFound.push_back(-1);notFound.push_back(-1);
        if(A == NULL || n < 1 || target < A[0] || target > A[n-1])
			return notFound;

		vector<int> res;
		int begin = 0, end = n-1;
		int mid = 0;
		bool isFound = false;
		while(begin <= end && !isFound)
		{
			mid = begin + (end - begin)/2;
			if(A[mid] == target) isFound = true;
			else if(A[mid] < target) begin = mid + 1;
			else end = mid - 1;
		}

		if(!isFound) return notFound;

		begin = mid;
		while(begin >= 0 && A[begin] == target) begin--;
		if(begin != mid) begin++;

		end = mid;
		while(end < n && A[end] == target) end++;
		if(end != mid) end--;

		res.push_back(begin);
		res.push_back(end);
		return res;
    }
};