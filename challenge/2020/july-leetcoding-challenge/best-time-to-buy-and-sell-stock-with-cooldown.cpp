// O(n) time and space DP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n)  return 0;
        
        vector<int> buy(n), sell(n);
        buy[0] = -prices[0];
        
        for(int i = 1; i < n; i++) {
            buy[i]  = max(buy[i-1], (i > 1 ? sell[i-2] : 0) - prices[i]);
            sell[i] = max(sell[i-1], buy[i] + prices[i]);
        }
        return sell[n-1];
    }
};

/*

To represent decision at index i:
1. buy[i] : max profit till index i, with series of transaction ending with "buy" (means we're holding certain stock from [0, i] to maximize profit)
2. sell[i]: max profit till index i, with series of transaction ending with "sell" (means we've sold certain stock from [0, i] to maximize profit)

So, till index i, the buy / sell action must happen and must be the last action. It may not happen at index i but may happen at i - 1, i - 2, ... 0.

Recursive formulation:
• buy[i]  - to make decision to buy stock at index i, we can either take rest and not buy it by using old decision at i-1, or sell at/before i-2 and buy at i (note: we cannot sell stock at i-1, because of cooldown of 1 day)
• sell[i] - to make decision to sell stock at index i, we can either take rest and not sell it by using old decision at i-1, or buy at/before i-1 and sell at i

We obtain these formulations:
• buy[i]  = max(buy[i], sell[i-2] - prices[i])
• sell[i] = max(sell[i], buy[i-1] + prices[i])

Consider prices = {1, 2, 3, 0, 2}

prices[i]:  1   2   3   0   2
buy[i]:    -1  -1  -1   1   1   
sell[i]:    0   1   2   2   3   <- max profit upto day n, with transaction ending with "sell" = 3

*/
