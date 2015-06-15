class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> numbers;
		for(int i = 0; i < nums.size(); i++){
			numbers.insert(nums[i]);
		}
		if(nums.size() > numbers.size())
			return true;
		else
			return false;
    }
};