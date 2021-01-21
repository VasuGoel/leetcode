// O(n • k) time and space, where n = length of prices, and k = no. of transactions (in this case, 2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), k = 2;
        vector<vector<int>> dp(k+1, vector<int>(n+1));
        
        for(int i = 1; i <= k; i++) {
            int val = INT_MIN;
            for(int j = 1; j <= n; j++) {
                val = max(val, dp[i-1][j] - prices[j-1]);
                dp[i][j] = max(dp[i][j-1], prices[j-1] + val);
            }
        }
        return dp[2][n];
    }
};
