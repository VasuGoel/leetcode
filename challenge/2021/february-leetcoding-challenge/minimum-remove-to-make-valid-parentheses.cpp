// O(n) time and space
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size(), k = 0;
        vector<int> v;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(')
                v.push_back(i);
            else if(s[i] == ')') {
                if(!v.empty() and s[v.back()] == '(')
                    v.pop_back();
                else
                    v.push_back(i);
            }
        }

        string res;
        for(int i = 0; i < n; i++) {
            if(k < v.size() and v[k] == i)
                k++;
            else
                res += s[i];
        }
        return res;
    }
};
