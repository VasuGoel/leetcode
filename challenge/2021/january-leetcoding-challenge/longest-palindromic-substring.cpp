// O(n^2) time, O(1) space. Two pointer approach.
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), maxlen = 0, pos = 0;
        
        for(int i = 0; i < n; i++) {
            int len = max(expandFromCenter(s, i, i), expandFromCenter(s, i, min(i+1, n-1)));
            if(len > maxlen) {
                maxlen = len;
                pos = i;
            }
        }
        return s.substr(pos-(maxlen-1)/2, maxlen);
    }
    
    int expandFromCenter(string &s, int l, int r) {
        while(l >= 0 and r < s.size() and s[l] == s[r])
            l--, r++;
        return r-l-1;
    }
};
