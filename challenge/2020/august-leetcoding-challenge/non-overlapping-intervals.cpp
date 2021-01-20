// O(n • logn) time, O(1) space. Idea is similar to Activity Selection problem, to select max non-overlapping intervals, and remaining intervals are required answer.
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](auto a, auto b) -> bool {
            return a[1] < b[1] or (a[1] == b[1] and a[0] < b[0]);
        });
        
        int n = intervals.size(), l = 0, selected = 0;
        for(int r = 0; r < n; r++) {
            if(!r or (intervals[l][1] <= intervals[r][0]))
                l = r, selected++;
        }
        return n - selected;
    }
};
