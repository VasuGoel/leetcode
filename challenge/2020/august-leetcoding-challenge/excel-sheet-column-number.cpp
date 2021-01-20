// O(n) time, O(1) space, where n = length of s
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(int i = s.size()-1, p = 0; i >= 0; i--, p++)
            res += pow(26, p) * (s[i]-'A'+1);
        
        return res;
    }
};
