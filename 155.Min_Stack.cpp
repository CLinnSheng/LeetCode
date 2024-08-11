#include <bits/stdc++.h>
using namespace std;

/*
Design a stack that can be retrieve the minimum element
since we want to retrieve the minimum element for any time of the stack
so we must have a stack that always store the latest min for any numbers in the stack
*/
class MinStack {
public:
    deque<int> Stack;
    deque<int> minStack;
    MinStack() {}
    
    void push(int val) {
        Stack.emplace_back(val);
        if (minStack.empty())
            minStack.emplace_back(val);
        else
            if (minStack.back() > val)
                minStack.emplace_back(val);
            else
                minStack.emplace_back(minStack.back());
    }
    
    void pop() {
        Stack.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        return Stack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */