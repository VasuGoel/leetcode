// O(n•logn) time, O(1) space. Activity selection problem.
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort intervals based on earliest finish times
        sort(points.begin(), points.end(), [&](auto a, auto b) -> bool {
            return a[1] < b[1] or (a[1] == b[1] and a[0] < b[0]);
        });
        
        // select max number of non-overlapping intervals, which will also be min number of arrows to burst balloons
        int arrows = 0, l = 0;
        for(int r = 0; r < points.size(); r++) {
            if(!r)  arrows++;
            else if(points[r][0] > points[l][1]) {
                l = r;
                arrows++;
            }
        }
        return arrows;
    }
};
