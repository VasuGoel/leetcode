// O(n) time and space
class Solution {
public:
    bool checkValidString(string s) {
        vector<int> stars, brackets;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '*')     stars.push_back(i);
            else {
                if(brackets.empty() or s[i] == '(' or (s[i] == ')' and s[brackets.back()] != '('))
                    brackets.push_back(i);
                else
                    brackets.pop_back();
            }
        }
        
        while(!brackets.empty()) {
            int i = brackets.back(); brackets.pop_back();
            
            if(s[i] == ')')
                while(!stars.empty() and stars.back() > i)  stars.pop_back();
            else
                while(!stars.empty() and stars.back() < i)  stars.pop_back();
            
            if(stars.empty())   return false;
            stars.pop_back();
        }
        
        return brackets.empty();
    }
};
