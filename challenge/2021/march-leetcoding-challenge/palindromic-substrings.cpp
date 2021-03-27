// Same idea as Longest Palindromic Substring. O(n^2) time, O(1) space
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            res += expandFromMid(s, i, i) + expandFromMid(s, i, i+1);
        }
        return res;
    }
    
    int expandFromMid(string &s, int l, int r) {
        int count = 0;
        while(l >= 0 and r < s.size() and s[l--] == s[r++])     count++;
        return count;
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// Dynamic Programming. O(n^2) time and space
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), count = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                if(s[i] == s[j] and (j+1 > i-1 or dp[i-1][j+1]))
                    dp[i][j] = 1, count++;
            }
        }
        return count;
    }
};
