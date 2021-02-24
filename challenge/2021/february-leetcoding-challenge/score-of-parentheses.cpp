// O(n) time and space. Using stack to store running score at each layer of parentheses.
class Solution {
public:
    int scoreOfParentheses(string S) {
        int cur = 0;
        stack<int> st;
        
        for(char c: S) {
            if(c == '(') {
                st.push(cur);
                cur = 0;
            }
            else {
                cur += st.top() + max(cur, 1);
                st.pop();
            }
        }
        return cur;
    }
};
