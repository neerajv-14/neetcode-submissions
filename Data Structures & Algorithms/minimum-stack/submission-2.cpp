class MinStack {
public:
    stack<int> st1, st2;
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        // if new element is less than equal to top element : push 

        // always maintain stack in increasing order : min at top. 
        // if val > stack's top: this will not contribute to get Min: because 
        // we already have a better minimum of left side, and those will not removed
        // unless this val is removed as per stack's order of deletion.
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
