class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int sz = digits.size();
		bool isCarry = false;
		int i = sz - 1;
		for(; i >= 0; i--)
		{
			if(digits[i] == 9){
				isCarry = true;
				digits[i]=0;
			}
			else{
				digits[i]++;
				isCarry = false;
				break;
			}
		}
		if((i == -1) && (isCarry == true))
		{
			digits.push_back(0);
			digits[0] = 1;
		}
		return digits;
    }
};