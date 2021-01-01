// Store pairs of element and min element seen so far
class MinStack {
    stack<pair<int,int>> st;
    
public:
    void push(int x) {
        st.push(st.empty() ? make_pair(x, x) : make_pair(x, min(x, this->getMin())));
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
