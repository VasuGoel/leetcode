// O(n^2) time, O(n) space DP
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict (wordDict.begin(), wordDict.end());

        int n = s.size();
        vector<bool> dp(n+1);
        dp[0] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j]) {
                    string word = s.substr(j, i-j);
                    if(dict.count(word)) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};
