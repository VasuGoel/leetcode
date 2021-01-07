// O(m • n) time and space DP. Similar to Maximal Square problem.
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 or j == 0)
                    dp[i][j] = matrix[i][j];
                else if(matrix[i][j])
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                
                res += dp[i][j];
            }
        }
        return res;
    }
};

/*

dp[i][j] means the size of biggest square with matrix[i][j] as bottom-right corner
dp[i][j] also means the number of squares with matrix[i][j] as bottom-right corner

• If A[i][j] == 0, no possible square
• If A[i][j] == 1, we compare the size of square dp[i-1][j-1], dp[i-1][j] and dp[i][j-1], where
    min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1 is the maximum size of square that we can find


*/
