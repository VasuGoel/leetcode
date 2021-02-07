// O(n) time and space. Two passes.
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size(), pos = -n;
        vector<int> ret(n, n);
        
        for(int i = 0; i < n; i++) {
            if(s[i] == c)   pos = i;
            ret[i] = i-pos;
        }
        
        for(int i = pos-1; i >= 0; i--) {
            if(s[i] == c)   pos = i;
            ret[i] = min(ret[i], pos-i);
        }
        return ret;
    }
};
