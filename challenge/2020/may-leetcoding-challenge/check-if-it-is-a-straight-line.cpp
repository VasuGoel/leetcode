// O(n) time, O(1) space
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int x1 = coordinates[1][0], y1 = coordinates[1][1];
        int dx = x1 - x0, dy = y1 - y0;
        
        for(auto co: coordinates) {
            int x = co[0], y = co[1];
            if(dy * (x - x1) != dx * (y - y1))
                return false;
        }
        return true;
    }
};

/*

The slope for a line through any 2 points (x0, y0) and (x1, y1) is (y1 - y0) / (x1 - x0).
Therefore, for any given 3 points (denote the 3rd point as (x, y)), if they are in a straight line, 
the slopes of the lines from the 3rd point to the 2nd point and the 2nd point to the 1st point must be equal:

(y - y1) / (x - x1) = (y1 - y0) / (x1 - x0)

In order to avoid being divided by 0, use multiplication form:

(x1 - x0) * (y - y1) = (x - x1) * (y1 - y0) =>
dx * (y - y1) = dy * (x - x1), where dx = x1 - x0 and dy = y1 - y0

*/
