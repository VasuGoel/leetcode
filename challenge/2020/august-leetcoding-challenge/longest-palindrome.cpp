// O(n) time, O(1) space
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq (128);
        for(char c: s)  freq[c]++;
        
        int res = 0;
        for(int x: freq) {
            if(x >= 2)  res += (x / 2) * 2;
        }
        return res == s.size() ? res : res+1;
    }
};
