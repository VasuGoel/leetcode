// O(n) time and space. Using stack. 
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        
        stack<char> st;
        for(char c: s) {
            if(c == '(' or c == '{' or c == '[')
                st.push(c);
            else {
                if(st.empty() or c != mp[st.top()])   
                    return false;
                
                st.pop();
            }
        }
        return st.empty();
    }
};
