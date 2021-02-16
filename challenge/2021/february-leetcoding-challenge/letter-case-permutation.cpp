// DFS
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        return dfs(s, 0);
    }
    
    vector<string> dfs(string s, int i) {
        vector<string> ret;

        if(i == s.size())   return {""};
        
        vector<string> remain = dfs(s, i+1);
        
        if(isdigit(s[i])) {
            for(string r: remain)
                ret.push_back(s[i] + r);
        }
        else {
            for(string r: remain) {
                ret.push_back((char)tolower(s[i]) + r);
                ret.push_back((char)toupper(s[i]) + r);
            }
        }
        return ret;
    }
};
