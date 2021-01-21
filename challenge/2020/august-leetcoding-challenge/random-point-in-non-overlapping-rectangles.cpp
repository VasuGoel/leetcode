/*
Note we have to find a random point among all rectangles randomly and uniformly. We cannot just pick random index from 'rects' array of rectangles
because it would introduce bias. Imagine there are 2 rectangles, one with area 100 and other with area 5, picking a random point from second rectangle is very high (50%)
despite smaller area.
To get a fair pick we have to consider their weights (area). This is same as https://leetcode.com/problems/random-pick-with-weight

Overall - O(logn) pick time. O(n) space
*/
class Solution {
    vector<vector<int>> r;
    vector<int> weights;
    
public:
    Solution(vector<vector<int>>& rects): r(rects) {
        int area = 0;
        for(auto &rect: rects) {
            // "+1" in area is to avoid cases when input is not rectangle like [5, 2, 5, 6]
            area += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            // store prefix sum of areas of rectangles
            weights.push_back(area);
        }
    }
    
    vector<int> pick() {
        // random pick with weight
        int i = upper_bound(weights.begin(), weights.end(), rand() % weights.back()) - weights.begin();
        auto rect = r[i];
        int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
        
        // for a randomly picked rectangle at index 'i', find random point (x, y) in it
        int x = x1 + rand() % (x2 - x1 + 1);        // random integer between [x1, x2]
        int y = y1 + rand() % (y2 - y1 + 1);        // random integer between [y1, y2]
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
