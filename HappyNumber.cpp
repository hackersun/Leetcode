class Solution {
public:
vector<int> getAllDigits(int num){
    vector<int> res;
    while(num){
        res.push_back(num%10);
        num /= 10;
    }
    return res;
}

bool isHappy(int n) {
    if(n == 0) return false;
    if(n < 0) n = -n;
    set<int> path;
    while(n != 1){
        if(path.find(n) != path.end())
            return false;
        else
            path.insert(n);
        
        vector<int> digits = getAllDigits(n);
        n = 0;
        for(int i = 0; i < digits.size(); i++){
            n += digits[i]*digits[i];
        }
    }
    return true;
}
};