class Solution {
public:
    int lengthOfLastWord(const char *s) {
		if(*s == '\0' || s == NULL) return 0;
        const char* p = s;
		while(*p) p++;
		while(p != s && *(p-1) == ' ') p--;
		if(p == s) return 0;

		const char* q = p;
		while(q != s && *(q-1) != ' ') q--;
		return p - q;
    }
};