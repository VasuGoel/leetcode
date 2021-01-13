// O(n • sqrt(n)) time, O(n) space DP
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        
        for(int i = 1; i <= n; i++) {
            int count = n;
            for(int j = 1; j*j <= i; j++)
                count = min(count, 1 + dp[i - j*j]);
            
            dp[i] = count;
        }
        return dp[n];
    }
};

/*

i:  0 1 2 3 4 5 6 7 8 9 10 11 12 
dp: 0 1 2 3 1 2 3 4 2 1 2  3  3 

Ex: For i = 12, we loop from 1 ≤ j ≤ sqrt(12) (or 3), 
When j = 1, dp[12] = dp[12 - 1*1] + 1 = dp[11] + 1 = 3 + 1 = 4
When j = 2, dp[12] = dp[12 - 2*2] + 1 = dp[8] + 1 = 2 + 1 = 3
When j = 3, dp[12] = dp[12 - 3*3] + 1 = dp[3] + 1 = 3 + 1 = 4

Since, min is at j = 2, which is 3, so dp[12] = 3, [4 + 4 + 4]

*/


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// Optimized for repeated function calls
class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp {0};
        
        while((int)dp.size() <= n) {
            int i = dp.size(), count = i;
            for(int j = 1; j*j <= i; j++)
                count = min(count, 1 + dp[i - j*j]);
            
            dp.push_back(count);
        }
        return dp[n];
    }
};
