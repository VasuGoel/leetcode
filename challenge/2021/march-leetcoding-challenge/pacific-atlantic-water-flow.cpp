// DFS
class Solution {
    vector<pair<int,int>> dirs {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty())  return {};
        int m = matrix.size(), n = matrix[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        
        for(int i = 0; i < m; i++) {
            dfs(matrix, i, 0, pacific);
            dfs(matrix, i, n-1, atlantic);
        }
        for(int j = 0; j < n; j++) {
            dfs(matrix, 0, j, pacific);
            dfs(matrix, m-1, j, atlantic);
        }
        
        vector<vector<int>> ret;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] and atlantic[i][j])    ret.push_back({i, j});
            }
        }
        return ret;
    }
    
    void dfs(vector<vector<int>> &matrix, int i, int j, vector<vector<bool>> &visited) {
        visited[i][j] = 1;

        for(auto dir: dirs) {
            int ni = i + dir.first, nj = j + dir.second;
            
            if(ni >= 0 and ni < matrix.size() and nj >= 0 and nj < matrix[0].size() and !visited[ni][nj] and matrix[ni][nj] >= matrix[i][j]) {
                dfs(matrix, ni, nj, visited);
            }
        }
    }
};

/*

Basic idea is to flood the water from pacific and atlantic boarders and at last check for each cell in matrix
if it can be visited by both pacific and atlantic, add that cell to result.

Since from the problem statement water from current cell can only move to cells with height lower or equal,
flooding from the borders would mean reverse of this and we only dfs for neighboring cells with height greater or equal.

*/
