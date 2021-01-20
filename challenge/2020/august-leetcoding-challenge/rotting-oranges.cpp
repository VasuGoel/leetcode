// Usual BFS and denote visited rotten cell or transition from fresh -> rotten by placing -1
class Solution {
    const vector<pair<int,int>> dirs {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), mins = 0;
        queue<pair<int,int>> q;

        for(int i = 0; i < m ; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2)
                    grid[i][j] = -1, q.push({i, j});
            }
        }
        
        while(!q.empty()) {
            int len = q.size();
            
            while(len--) {
                auto cur = q.front(); q.pop();
                
                for(auto dir: dirs) {
                    int x = cur.first + dir.first, y = cur.second + dir.second;
                    
                    if(x >= 0 and x < m and y >= 0 and y < n and grid[x][y] == 1)
                        grid[x][y] = -1, q.push({x, y});
                }
            }
            if(!q.empty())   mins++;    // if any fresh oranges were changed to rotten then a minute must pass
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] ==  1)    return -1;          // return -1 if any fresh orange still remains after bfs
                if(grid[i][j] == -1)    grid[i][j] = 2;     // reverting changed cells to original to make it thread safe
            }
        }
        return mins;
    }
};
