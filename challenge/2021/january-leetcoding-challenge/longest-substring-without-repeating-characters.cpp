// O(n) time, O(1) space. Two pointer approach.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, l = 0;
        vector<int> last(128, -1);
        
        for(int r = 0; r < s.size(); r++) {
            l = max(l, last[s[r]] + 1);
            res = max(res, r-l+1);
            last[s[r]] = r;
        }
        return res;
    }
};
