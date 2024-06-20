class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return;

    }
    
    int pop() {
        if(!s1.empty())
        {
            int x = s1.top();
            s1.pop();
            return x;
        }
        else{
            return -1;
        }
    }
    
    int peek() {
        if(!s1.empty())
        {
            int x = s1.top();
            return x;
        }
        else{
            return -1;
        }
        
    }
    
    bool empty() {
        return s1.empty();
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