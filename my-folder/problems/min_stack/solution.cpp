class MinStack {
    stack<int> mini;
    stack<int> stk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(mini.empty())
            mini.push(val);
        else if(val <= mini.top())
            mini.push(val);
    }
    
    void pop() {
        int x = stk.top();

        if(x == mini.top())
            mini.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mini.top();
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