class MinStack {
public:
    stack<int> st1, st2;
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        
        if(st2.empty() || st2.top()>=val)st2.push(val);
    }
    
    void pop() {
        int val = st1.top();
        st1.pop();
        if(val==st2.top())st2.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};
