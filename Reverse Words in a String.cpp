class Solution {
public:
    void reverseWords(string &s) {
        stack<string> words;
		int fpos= 0, spos = 0;
		while((spos = s.find(' ', fpos)) != string::npos){
			if(spos > fpos)
				words.push(string(s, fpos, spos-fpos));
			fpos = spos + 1;
		}
		if(fpos < s.size())
			words.push(string(s, fpos));
		s = "";
		while(!words.empty()){
			s += words.top();
			words.pop();
			if(!words.empty())
				s += " ";
		}
    }
};