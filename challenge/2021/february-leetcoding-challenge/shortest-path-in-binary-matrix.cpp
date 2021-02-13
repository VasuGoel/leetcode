// Usual BFS
class Solution {
    const vector<vector<int>> dirs {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), steps = 0;
        vector<vector<bool>> seen(n, vector<bool>(n));
        
        queue<vector<int>> q;
        if(!grid[0][0])  
            q.push({0,0}), seen[0][0] = 1;
        
        while(!q.empty()) {
            steps++;
        
            int len = q.size();
            while(len--) {
                auto cur = q.front(); q.pop();

                if(cur[0] == n-1 and cur[1] == n-1)
                    return steps;

                for(auto dir: dirs) {
                    int x = cur[0] + dir[0], y = cur[1] + dir[1];
                    if(x >= 0 and x < n and y >= 0 and y < n and !grid[x][y] and !seen[x][y]) {
                        q.push({x, y});
                        seen[x][y] = 1;
                    }
                }
            }
        }
        return -1;
    }
};


// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// Dynamic Programming [Wrong Answer]
class Solution {
    const vector<vector<int>> dirs {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, n+n));
        dp[0][0] = 1;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!grid[i][j]) {
                    int res = dp[i][j];
                    
                    for(auto dir: dirs) {
                        int x = i + dir[0], y = j + dir[1];
                        if(x >= 0 and x < n and y >= 0 and y < n and !grid[x][y])
                            res = min(res, dp[x][y]+1);
                    }
                    dp[i][j] = res;
                }
            }
        }
        return dp[n-1][n-1] == n+n ? -1 : dp[n-1][n-1];
    }
};

/*

• Why does DP not work here?

It is because of the way we are traversing the maze when doing the DP algorithm. If the path to the answer is complex enough, you won't calculate the cells in right order.
Ex: For the following input - 

[
[0,1,0,0,0],
[0,1,0,1,0],
[0,1,0,1,0],
[0,1,0,1,0],
[0,0,0,1,0]
]

In DP algorithm, by the time you are calculating, for example, cell (1,2), you still have't calculated the value for cell (2,2). For DP to work there, 
you would have to write a code that does that path instead of the usual row in range(len(dp)) col in range(len(dp[row])).

This is where BFS wins (or DFS, even though BFS is more recommended for this problem), in which you follow a path that is dictated by the queue of neighbors.

*/
