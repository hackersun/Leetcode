class Solution {
public:
    int binarySearch(vector<int> &num, int begin, int end)
{
	if(begin == end) return num[begin];
	if(num[begin] < num[end]) return num[begin];
	else
	{
		int mid = (end - begin)/2 + begin;
		if(num[begin] < num[mid]) return binarySearch(num, mid+1, end);
		else if(num[begin] > num[mid]) return binarySearch(num, begin, mid);
		else return num[begin] < num[end] ? num[begin] : num[end];
	}
}

int findMin(vector<int> &num) {
        return binarySearch(num, 0, num.size()-1);
    }
};