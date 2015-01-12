class Solution {
public:
int find(vector<int> num, int begin, int end)
{
	int res = num[begin];
	for(int i = begin+1; i <= end; i++)
		if(res > num[i]) res = num[i];
	return res;
}

int binarySearch(vector<int> num, int begin, int end)
{
	if(begin == end) return num[begin];
	if(num[begin] < num[end]) 
		return num[begin];
	else if(num[begin] == num[end]) 
		return find(num, begin, end);
	else{
		int mid = begin + (end - begin)/2;
		if(num[begin] < num[mid]) 
			return binarySearch(num, mid+1, end);
		else if(num[begin] > num[mid])
			return binarySearch(num, begin, mid);
		else
			return find(num, mid, end);
	}
}

int findMin(vector<int> &num) {
	return binarySearch(num, 0, num.size()-1);
}
};


//method 2
int find(vector<int> num, int begin, int end)
{
	int res = num[begin];
	for(int i = begin+1; i <= end; i++)
		if(res > num[i]) res = num[i];
	return res;
}

int findMin(vector<int> &num) {
		int begin = 0, end = num.size()-1;
		if(num[begin] < num[end]) return num[begin];
		while(begin <= end)
		{
			if(begin == end) return num[begin];
			if(num[begin] < num[end])return num[begin];
			else if(num[begin] == num[end])
				return find(num, begin, end);
			else{
				int mid = begin + (end - begin)/2;
				if(num[begin] < num[mid])
					begin = mid + 1;
				else if(num[begin] > num[mid])
					end = mid;
				else 
					return find(num, mid, end);
			}
		}
    }