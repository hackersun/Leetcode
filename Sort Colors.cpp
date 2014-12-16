class Solution {
public:
    void sortColors(int A[], int n) {//version 1
        int red = 0;
		int white = 0;
		int blue = 0;
		for(int i = 0; i < n; i++)
		{
			if(A[i] == 0) red++;
			else if(A[i] == 1) white++;
			else blue++;
		}
		int i = 0;
		while(i < red) A[i++] = 0;
		while(i < red+white) A[i++] = 1;
		while(i < n) A[i++] = 2;
    }
};

class Solution {
public:
    void sortColors(int A[], int n) {//version 2
        int red = 0;
		int blue = n-1;
		for(int i = 0; i <= blue; i++)
		{
			if(A[i] == 0) swap(A[red++], A[i]);
			if(A[i] == 2) swap(A[i--], A[blue--]);
		}
    }
};