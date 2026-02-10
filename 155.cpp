#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (min.empty() || min.top() >= val) {
            min.push(val);
        }
        s.push(val);
    }
    
    void pop() {
        int v = s.top();
        if (v == min.top()) min.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }

private:
    stack<int> min;
    stack<int> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */