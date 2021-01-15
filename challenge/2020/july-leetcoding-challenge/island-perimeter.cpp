// O(m • n) time, O(1) space, where m = no. of rows, and n = no. of columns
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        
        // lambda to count borders around cell(i, j)
        auto borders = [&](int i, int j) -> int {
            int res = 0;
            vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
            
            for(auto dir: dirs) {
                int x = i + dir[0], y = j + dir[1];
                if((x < 0 or x >= m or y < 0 or y >= n) or grid[x][y] == 0)
                    res++;
            }
            return res;
        };
        
        // count all borders for each cell(i, j) == 1
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                if(grid[i][j])  res += borders(i, j);
        }
        return res;
    }
};
