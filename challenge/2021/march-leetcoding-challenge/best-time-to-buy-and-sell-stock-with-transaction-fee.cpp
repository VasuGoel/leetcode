// O(n) time, O(1) space
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int p0 = -prices[0], p1 = 0;
        
        for(int i = 1; i < prices.size(); i++) {
            p0 = max(p0, p1 - prices[i]);
            p1 = max(p1, p0 + prices[i] - fee);
        }
        return p1;
    }
};

/*

At day 'i' we only have 2 states for day 'i-1'
0 -> we own/hold a stock
1 -> we don't own/hold a stock

Iterate over all prices, and for each prices[i], keep track of 2 variables:
p0 -> max profit when we hold a stock on day 'i-1'
p1 -> max profit when we don't hold a stock on day 'i-1'

For current prices[i], the max value for each state are as follows:
p0 -> either hold stock from day 'i-1' or buy new stock, (p1 - prices[i])
p1 -> either keep not holding stock or sell stock we already own (p0 + prices[i] - fee)

*/
