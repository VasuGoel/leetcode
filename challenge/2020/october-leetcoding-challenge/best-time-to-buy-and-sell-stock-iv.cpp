// O(k • n) time and space, where k = max no. of transactions, and n = no. of prices
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k >= n/2)    
            return buyAndSellStock(prices);
        
        vector<vector<int>> dp(k+1, vector<int>(n));
        for(int i = 1; i <= k; i++) {
            int c = INT_MIN;
            for(int j = 1; j < n; j++) {
                c = max(c, dp[i-1][j-1] - prices[j-1]);
                dp[i][j] = max(dp[i][j-1], prices[j] + c);
            }
        }
        return dp[k][n-1];
    }
    
    // similar to problem buy and sell stock ii
    int buyAndSellStock(vector<int> &prices) {
        int profit = 0;
        for(int i = 1; i < prices.size(); i++)
            if(prices[i] > prices[i-1])
                profit += prices[i] - prices[i-1];
        
        return profit;
    }
};
