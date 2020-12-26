// O(n) time, O(1) space
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, res = 0;
        vector<int> lastSeen(129, -1);
        
        for(int r = 0; r < s.size(); r++) {
            l = max(l, lastSeen[s[r]] + 1);
            res = max(res, r-l+1);
            lastSeen[s[r]]= r;
        }
        return res;
    }
};
