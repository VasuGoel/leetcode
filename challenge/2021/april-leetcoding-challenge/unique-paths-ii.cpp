class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 and j == 0)    dp[i][j] = obstacleGrid[i][j] != 1 ? 1 : 0;
                else if(obstacleGrid[i][j] != 1) {
                    dp[i][j] = ((i-1 >= 0 && obstacleGrid[i-1][j] != 1) ? dp[i-1][j] : 0) + ((j-1 >= 0 && obstacleGrid[i][j-1] != 1 ) ? dp[i][j-1] : 0);   
                }
            }
        }
        return dp[m-1][n-1];
    }
};
