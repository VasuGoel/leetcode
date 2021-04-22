// For each potential cut position which is at the edge of any brick, count number of brick edges for all rows.O(rows * bricks) time
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size(), res = n;
        unordered_map<int,int> edges;
        
        for(auto row: wall) {
            for(int i = 0, width = 0; i < row.size()-1; i++) {      // skip last brick edge
                width += row[i];
                edges[width]++;
            }
        }
        
        for(auto e: edges)  res = min(res, n - e.second);
        return res;
    }
};
