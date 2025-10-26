class MinStack {
public:
    vector<long long> st;  // use long long for safe encoding
    long long minVal;

    MinStack() {
        minVal = LLONG_MAX;
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push_back(val);
            minVal = val;
        } 
        else if (val >= minVal) {
            st.push_back(val);
        } 
        else {
            // encode previous min
            st.push_back(2LL * val - minVal);
            minVal = val;
        }
    }
    
    void pop() {
        if (st.empty()) return;
        long long topVal = st.back();
        st.pop_back();
        if (topVal < minVal) {
            // decode old min
            minVal = 2LL * minVal - topVal;
        }
    }
    
    int top() {
        long long topVal = st.back();
        if (topVal < minVal)
            return (int)minVal;
        return (int)topVal;
    }
    
    int getMin() {
        return (int)minVal;
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