class Solution {//method 1: bfs, Time Limit Exceeded
public:
    bool canJump(int A[], int n) {
        if(A == NULL || n < 2) return true;
		vector<int*> path;
		path.push_back(A);
		int* target = A + n;
		while(!path.empty())
		{
			int* tmp = path[0];
			for(int i = 1; i <= *tmp; i++)
				if(tmp + i == target)
					return true;
				else
					path.push_back(tmp+i);
			path.erase(path.begin());
		}
		return false;
    }
};

class Solution {//method 2
public:
    bool canJump(int A[], int n) {
        if(A == NULL || n < 2) return true;
		int jump = 0;
		for(int i = 0; i < n-1; i++, jump--)
		{
			jump = max(jump, A[i]);
			if(jump <= 0) return false;
		}
		return true;
    }
};
