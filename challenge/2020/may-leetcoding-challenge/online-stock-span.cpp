// O(1) amortized time 'next()' operation, O(n) space to maintain monotonically decreasing stack.
class StockSpanner {
    stack<pair<int,int>> st;        // store pair of {stock price, span of stock}
    
public:
    int next(int price) {
        int span = 1;
        while(!st.empty() and st.top().first <= price)     
            span += st.top().second, st.pop();
        
        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
