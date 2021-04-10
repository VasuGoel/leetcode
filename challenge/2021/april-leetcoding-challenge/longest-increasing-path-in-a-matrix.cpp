// DFS with memoization
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty())  return 0;
        int m = matrix.size(), n = matrix[0].size(), longestSeq = 1;
        vector<vector<int>> memo(m, vector<int>(n));       // for memoization
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int len = dfs(matrix, i, j, INT_MIN, memo);
                longestSeq = max(longestSeq, len);
            }
        }
        return longestSeq;
    }
    
    int dfs(vector<vector<int>> &matrix, int i, int j, int prev, vector<vector<int>> &memo) {
        if(i < 0 or i >= matrix.size() or j < 0 or j >= matrix[0].size() or matrix[i][j] <= prev)   
            return 0;
        
        if(memo[i][j] != 0)    
            return memo[i][j];     // return memoized result
        
        int up = dfs(matrix, i-1, j, matrix[i][j], memo);
        int right = dfs(matrix, i, j+1, matrix[i][j], memo);
        int down = dfs(matrix, i+1, j, matrix[i][j], memo);
        int left = dfs(matrix, i, j-1, matrix[i][j], memo);
        return memo[i][j] = 1 + max({up, right, down, left});     // memoize
    }
};
