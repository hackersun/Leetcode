class Solution {
public:
    int maxArea(vector<int> &height) {//Version 2: O(n)
		int size = height.size();
		int left = 0, right = size - 1;
		int res = 0;
		while(left < right)
		{
			int h = height[left] < height[right] ? height[left] : height[right];
			int tmp = h * (right - left);
			if(tmp > res) res = tmp;
			if(h == height[left]) left++;
			else right--;
		}
		return res;
    }
};