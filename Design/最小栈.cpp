/*
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
*/

// 用两个栈，一个栈来存储所有值，另一个栈来存储出现的最小值 
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        // 只有push 的元素小于等于 最小栈的栈顶元素时，才push入最小栈
        if ( mins.empty() || x <= mins.top() ) 
            mins.push(x);
    }
    
    void pop() {
        // 只有pop出去的元素等于最小栈的栈顶元素时，才pop 
        if ( s.top() == mins.top() ) 
            mins.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
private:
    stack<int> s, mins;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */