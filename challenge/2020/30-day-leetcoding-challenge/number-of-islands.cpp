// DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), islands = 0;
        vector<vector<bool>> seen(m, vector<bool>(n));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' and !seen[i][j]) {
                    islands++;
                    dfs(grid, i, j, seen);
                }
            }
        }
        return islands;
    }
    
    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &seen) {
        if(i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or seen[i][j] or grid[i][j] == '0')
            return;
        
        seen[i][j] = 1;
        dfs(grid, i-1, j, seen);
        dfs(grid, i, j+1, seen);
        dfs(grid, i+1, j, seen);
        dfs(grid, i, j-1, seen);
    }
};


// ------------------------------------------------------------------------------------------–––


// BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), islands = 0;
        vector<vector<bool>> seen(m, vector<bool>(n));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' and !seen[i][j]) {
                    islands++;
                    bfs(grid, i, j, seen);
                }
            }
        }        
        return islands;
    }
    
    void bfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &seen) {
        vector<vector<int>> dirs {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        queue<vector<int>> q;
        seen[i][j] = 1;
        q.push({i, j});
        
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            
            for(auto dir: dirs) {
                int x = cur[0] + dir[0], y = cur[1] + dir[1];
                if(x >= 0 and x < grid.size() and y >= 0 and y < grid[0].size() and grid[x][y] == '1' and !seen[x][y]) {
                    seen[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
    }
};
