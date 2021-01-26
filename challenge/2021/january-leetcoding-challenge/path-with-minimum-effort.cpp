// O(m•n•log(m•n)) time, O(m•n) space. Dijkstra's Algorithm on 2D grid.
class Solution {
    const vector<vector<int>> dirs {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        
        // custom comparator to sort set based on distance
        auto comp = [](auto a, auto b) { return a[0] < b[0]; };
        set<vector<int>> s;
        s.insert({0, 0, 0});    // stores {distance, row, column}
        
        while(!s.empty()) {
            // pull out cell with min distance
            auto it = s.begin();
            int d = (*it)[0], r = (*it)[1], c = (*it)[2];
            s.erase(it);
            
            // if reached bottom right cell
            if(r == m-1 and c == n-1)   return d;
            
            for(auto dir: dirs) {
                int nr = r + dir[0], nc = c + dir[1];
                
                if(nr >= 0 and nr < m and nc >= 0 and nc < n) {
                    int newDist = max(d, abs(heights[r][c] - heights[nr][nc]));
                    
                    if(newDist < dist[nr][nc]) {
                        dist[nr][nc] = newDist;
                        s.insert({newDist, nr, nc});
                    }
                }
            }
        }
        return 0;
    }
};

/*

• The problem is to find the shortest path with minimum distance, where distance is defined as maximum absolute difference in heights between two consecutive cells of the path.
• The first idea that comes to mind is to use Dijikstra's algorithm, which costs O(E log V), where E is number of edges E = 4*M*N, V is number of veritices V = M*N

*/


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// DFS/Backtracking [TLE]
class Solution {
    const vector<vector<int>> dirs {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int res = INT_MAX;
        
        // track visited cells to avoid revisiting
        vector<vector<bool>> seen(m, vector<bool>(n));
        seen[0][0] = 1;
        dfs(heights, 0, 0, seen, 0, res);
        return res;
    }
    
    // try all possible 4-directional path combinations
    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &seen, int max_effort, int &res) {
        int m = grid.size(), n = grid[0].size();
        // if reached last cell
        if(i == m-1 and j == n-1) {
            // update res with min value of 'max_effort' among all paths
            res = min(res, max_effort);
            return;
        }
        
        // recur 4-directionally
        for(auto dir: dirs) {
            int x = i + dir[0], y = j + dir[1];
            
            if(x >= 0 and x < grid.size() and y >= 0 and y < grid[0].size() and !seen[x][y]) {
                seen[x][y] = 1;
                dfs(grid, x, y, seen, max(max_effort, abs(grid[i][j] - grid[x][y])), res);
                seen[x][y] = 0;
            }
        }
    }
};
