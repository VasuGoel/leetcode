// O(m • n) time and space DP, where m = no. of rows, and n = no. of columns
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        // dp[i][j] means 'max side of square' ending at cell (i, j)
        vector<vector<int>> dp(m, vector<int>(n));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 or j == 0)
                    dp[i][j] = matrix[i][j] - '0';
                else if(matrix[i][j] == '1')
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                
                res = max(res, dp[i][j]);
            }
        }
        return res * res;   // return area
    }
};
