/*
 * Implement the queue using a stack
 * */
#include <stack>
class MyQueue
{
  public:
    std::stack<int> stack;
    MyQueue()
    {
    }

    // push to the back
    void push(int x)
    {
        stack.push(x);
    }

    // remove from the front & return it
    int pop()
    {
        std::stack<int> temp;
        while (stack.size())
        {
            temp.push(stack.top());
            stack.pop();
        }

        int front{temp.top()};
        temp.pop();

        while (temp.size())
        {
            stack.push(temp.top());
            temp.pop();
        }
        return front;
    }

    // return the element at front
    int peek()
    {
        std::stack<int> temp(stack);
        int val;

        while (temp.size())
        {
            val = temp.top();
            temp.pop();
        }
        return val;
    }

    bool empty()
    {
        return stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
