// O(n^2) time, O(1) space
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, maxlen = 0;
        
        for(int i = 0; i < n; i++) {
            int l1 = expandFromMid(s, i, i);
            int l2 = expandFromMid(s, i, min(i+1, n-1));
            int len = max(l1, l2);
            
            if(len > maxlen)
                maxlen = len, start = i - (len - 1) / 2;
        }
        return s.substr(start, maxlen);
    }
    
    int expandFromMid(string &s, int l, int r) {
        if(s[l] != s[r])    return 0;
        while(l > 0 and r < s.size()-1 and s[l-1] == s[r+1])  l--, r++;
        return r-l+1;
    }
};


// -------------------------------------------------------------------------------------------–


// O(n^2) time and space DP
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, maxlen = 1;
        vector<vector<int>> dp(n, vector<int>(n));
        
        // longest palindromic substring in substrings of len 1 is 1
        for(int i = 0; i < n; i++)  dp[i][i] = 1;
        
        // traversing daigonally and considering all substrings
        for(int l = 1; l < n; l++) {
            for(int i = 0; i < n; i++) {
                int j = i + l;
                if(j < n) {
                    // in substring from i to j, if characters at index i and j match check if dp[i+1][j-1] is also non-zero (means substring from i+1 to j-1 is also valid, say, i=0, j=3 in "ansa") or if, j-1 = 1 (substring is of len 2, say, i=2, j=3 in "cbbd")
                    if(s[i] == s[j] and (dp[i+1][j-1] != 0 or j-i == 1))
                        dp[i][j] = 2 + dp[i+1][j-1];

                    if(dp[i][j] > maxlen) {
                        maxlen = dp[i][j];
                        start = i;
                    }   
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
