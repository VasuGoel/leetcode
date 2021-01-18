// O(n) time, O(1) space. Fibonacci number.
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 0;
        
        for(int i = 1; i <= n; i++) {
            int next = a + b;
            b = a;
            a = next;
        }
        return a;
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(n) time and space DP
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = 1, dp[1] = 1;
        
        for(int i = 2; i <= n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        
        return dp[n];
    }
};
