// O(m • n) time and space DP
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // dp[i][j] means total no. of combination using coin 'i' in coins to make amount 'j'
        vector<vector<int>> dp(n+1, vector<int>(amount+1));
        
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= amount; j++) {
                // if amount equals 0, there's only 1 possible combination regardless of types of coins, i.e. no combination
                if(j == 0)
                    dp[i][j] = 1;
                // total combinations to make amount 'j' = no. of combinations excluding and including coin 'i'
                else if(i)
                    dp[i][j] = dp[i-1][j] + (j >= coins[i-1] ? dp[i][j-coins[i-1]] : 0);
            }
        }
        return dp[n][amount];
    }
};
