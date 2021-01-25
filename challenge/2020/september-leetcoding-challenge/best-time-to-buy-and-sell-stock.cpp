// O(n) time, O(1) space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, min_price = prices[0];
        
        for(int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i]-min_price);
            min_price = min(min_price, prices[i]);
        }
        return profit;
    }
};
