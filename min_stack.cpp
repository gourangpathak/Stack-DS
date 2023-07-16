class MinStack {
private:
    stack<int> st;
    stack<int> minst;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minst.empty()) {
            minst.push(val);
        }
        else {
            if(minst.top() >= val) {
                minst.push(val);
            }
        }
    }
    
    void pop() {
        if(st.top() == minst.top()) {
            minst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
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