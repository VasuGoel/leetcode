// Backtracking
class Solution {
    const vector<vector<int>> dirs {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), x, y;
        int paths = 0, empty = 0;
        
        // find starting square cell (x, y) and count empty cells to walk over
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    x = i, y = j;
                if(grid[i][j] == 0)     
                    empty++;
            }
        }
        
        // track visited cells to avoid revisiting them
        vector<vector<bool>> seen(m, vector<bool>(n));
        dfs(grid, x, y, empty, seen, paths);
        return paths;
    }
    
    // try all possible 4-directional path combinations
    void dfs(vector<vector<int>> &grid, int i, int j, int empty, vector<vector<bool>> &seen, int &paths) {       
        // if we're at ending square, stop recuring further
        if(grid[i][j] == 2) {
            // if all empty cells are exhausted (-1 bcoz in prev recursive call empty == 0), increment paths
            if(empty == -1)  paths++;
            return;
        }
        
        // recur 4-directionally
        for(auto dir: dirs) {
            int x = i + dir[0], y = j + dir[1];

            // if new cell is valid and not already visited and either empty or ending cell
            if(x >= 0 and x < grid.size() and y >= 0 and y < grid[0].size() and !seen[x][y] and (grid[x][y] == 0 or grid[x][y] == 2)) {
                seen[x][y] = 1;                             // mark cell visited
                dfs(grid, x, y, empty-1, seen, paths);      // recur
                seen[x][y] = 0;                             // undo/backtrack
            }
        }
    }
};
