class Solution {
public:
    bool isValid(string s) {
		if(s.size() < 1) return true;
		if(s.size() % 2) return false;
		stack<char> stk;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '(' || s[i] == '{' || s[i] == '[')
				stk.push(s[i]);
			else{
				if(stk.empty()) return false;
				char top = stk.top(); stk.pop();
				if(!(s[i] == ')' && top == '(' ||
					s[i] == ']' && top == '[' ||
					s[i] == '}' && top == '{'))
					return false;
			}
		}
		if(stk.empty()) return true;
		else return false;
    }
};