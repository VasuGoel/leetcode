// O(366) time and space DP
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp (366);
        
        for(int i = 1, d = 0; d < days.size(); i++) {
            if(i == days[d]) {
                dp[i] = min({costs[0] + dp[i-1], 
                             costs[1] + (i >=  7 ? dp[i-7]  : 0), 
                             costs[2] + (i >= 30 ? dp[i-30] : 0)});
                d++;
            }
            else
                dp[i] = dp[i-1];
        }
        return dp[days.back()];
    }
};

/*

For each travel day, we can buy a one-day ticket, or use 7-day or 30-day pass as if we would have purchased it 7 or 30 days ago. 
We need to track rolling costs for at least 30 days back, and use them to pick the cheapest option for the next travel day.
Here, we can use two approaches: track cost for all calendar days, or process only travel days. 

We track the minimum cost for all calendar days in dp. For non-travel days, the cost stays the same as for the previous day. 
For travel days, it's a minimum of yesterday's cost plus single-day ticket, or cost for 7 days ago plus 7-day pass, 
or cost 30 days ago plus 30-day pass.

*/


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// Space optimized. O(365) days, O(30) space DP.
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp (30);
        
        for(int i = 1, d = 0; d < days.size(); i++) {
            if(i == days[d]) {
                dp[i % 30] = min({costs[0] + dp[(i-1) % 30],
                                  costs[1] + (i >=  7 ? dp[(i-7) % 30] : 0),
                                  costs[2] + (i >= 30 ? dp[(i-30) % 30] : 0)});
                d++;
            }
            else
                dp[i % 30] = dp[(i-1) % 30];
        }
        return dp[days.back() % 30];
    }
};
