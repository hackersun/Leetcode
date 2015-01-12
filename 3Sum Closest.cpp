class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
		int closet = INT_MAX >> 1;
		for(int i = 0; i < num.size() - 2; i++)
		{
			int left = i+1, right = num.size() - 1;
			while(left < right)
			{
				int tmp = num[i] + num[left] + num[right];
				if(tmp == target)
					return target;
				
				if(abs(target - closet) > abs(target - tmp))
						closet =  tmp;

				if(tmp > target)
					right--;
				else
					left++;
			}
		}
		return closet;
    }
};