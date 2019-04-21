/*
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        s.push(x);
        if ( min_s.empty() || min_s.top() >= x )
            min_s.push(x);
    }

    void pop() {
        if ( s.empty() )
            return;
        int top = s.top();
        s.pop();
        if ( !min_s.empty() && min_s.top() == top )
            min_s.pop();
    }

    int top() {
        if ( s.empty() )
            return 0;
        return s.top();
    }

    int getMin() {
        if ( !min_s.empty() )
            return min_s.top();
        return s.top();
    }
private:
    stack<int> s;
    stack<int> min_s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
