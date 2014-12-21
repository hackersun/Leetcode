class Solution {
public:
    bool binarySearchInARow(vector<int> arr, int begin, int end, int target)
{

	while(begin <= end)
	{
		int mid = begin + (end - begin)/2;
		if(arr[mid] == target) return true;
		else if(arr[mid] < target) begin = mid+1;
		else end = mid - 1;
	}
	return false;
}
bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = matrix.size();
		int col = matrix[0].size();

		int begin = 0, end = row-1;
		int mid = 0;
		while(begin < end)
		{
			mid = begin + (end - begin)/2;
			if(target == matrix[mid][0]) return true;
			else if(target < matrix[mid][0]) end = mid - 1;
			else if(begin == mid){
				if(target < matrix[mid+1][0]) end = begin;
				else begin = end;
			}else begin = mid;
		}
		if(begin > end) return false;
		else if(begin == end)return binarySearchInARow(matrix[begin], 0, col-1, target);
    }
};