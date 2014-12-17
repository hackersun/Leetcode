class Solution {
public:
    int findPeakElement(const vector<int> &num) {//stupid O(n), compare 2n times.
        int sz = num.size();
		for(int index = 0; index < sz; index++)
		{
			bool isleft = true;
			bool isright = true;
			if(index > 0) isleft = num[index-1] < num[index] ? true : false;
			if(index <= sz-2) isright = num[index] > num[index+1] ? true : false;
			if(isleft && isright) return index;
		}
		return -1;
    }
};

int findPeakElement(const vector<int> &num) {//smart O(n), compare n times.
        for(int i=1; i<num.size(); i++){
            if(num[i] < num[i-1])
                return i-1;
        }
        return num.size()-1;
    }

int findPeakElement(const vector<int> &num) {//O(logN)
        int left=0,right=num.size()-1;
        while(left<=right){
            if(left==right)
                return left;
            int mid=(left+right)/2;
            if(num[mid]<num[mid+1])
                left=mid+1;
            else
                right=mid;
        }
    }