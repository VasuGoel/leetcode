// O(n•logn) time, O(1) space
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](auto a, auto b) -> bool {
            return a[0] < b[0] or (a[0] == b[0] and a[1] > b[1]);
        });
        
        int res = 0, r = -1;
        for(auto i: intervals) {
            if(i[1] > r) {
                r = i[1];
                res++;
            }
        }
        return res;
    }
};

/*

Sort intervals in such an order that only previous ones are possible to cover current one.

• Sort by the left bound, and when left bounds are equal, sort right bounds by reverse order; Therefore, no interval can cover previous ones.
• Loop through the intervals, whenever current right most bound < next interval's right bound, it means current interval can NOT cover next interval, update right most bound and increase counter by 1.

*/
