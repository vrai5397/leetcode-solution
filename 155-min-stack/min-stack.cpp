class MinStack {
public:
vector<int> record;
stack<int> st;
    MinStack() {
        
    }
    
    void push(int value) {
        
        st.push(value);
        if(record.size()==0)
        record.push_back(value);
       else if(value<=record.back())
         record.push_back(value);
    }
    
    void pop() {
        if(st.top()==record.back()){
            st.pop();
            record.pop_back();
        }
        else st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return record.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */