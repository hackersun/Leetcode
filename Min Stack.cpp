#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<queue>
class MinStack {
public:
    stack<int> stk;
    stack<int> min;
    void push(int x) {
        stk.push(x);
        if(min.empty() || x <= min.top()) min.push(x);
    }

    void pop() {
        int top = stk.top();
        stk.pop();
        if(top == min.top()) min.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min.top();
    }
};