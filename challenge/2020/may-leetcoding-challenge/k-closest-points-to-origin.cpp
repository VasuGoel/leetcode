// O(n • logn) time, O(1) space
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {       
        // lambda to compute square of distance of points from origin
        auto eud = [&](auto &p) -> int { return p[0] * p[0] + p[1] * p[1]; };
        
        sort(points.begin(), points.end(), [&](auto &a, auto &b) {
            return eud(a) < eud(b);
        });
        points.resize(K);
        return points;
    }
};
