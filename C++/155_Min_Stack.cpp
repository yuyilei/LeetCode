class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> min, tmp ; 
    MinStack() {
        
    }
    
    void push(int x) {
        tmp.push(x) ; 
        if ( min.empty() || min.top() >= x ) min.push(x) ; 
    }
    
    void pop() {
        if ( min.top() == tmp.top() ) min.pop() ; 
        tmp.pop() ; 
    }
    
    int top() {
        return tmp.top() ; 
    }
    
    int getMin() {
        return min.top() ; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */