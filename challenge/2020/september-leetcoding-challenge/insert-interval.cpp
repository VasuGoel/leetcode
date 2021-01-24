// O(n) time and space
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // find first interval with start point greater or equal to newInterval's start
        int pos = lower_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
        // check if newInterval can be merged with previous interval
        if(pos > 0 and intervals[pos-1][1] >= newInterval[0])   pos--;
        
        vector<vector<int>> ret;
        // insert all intervals to the left of 'pos'
        for(int i = 0; i < pos; i++)
            ret.push_back(intervals[i]);
        
        ret.push_back(newInterval);
        
        // merge remaining intervals with 'newInterval' if they intersect
        for(int i = pos; i < intervals.size(); i++) {
            auto &last = ret.back(), cur = intervals[i];
            
            if(last[1] >= cur[0])
                last[0] = min(last[0], cur[0]), last[1] = max(last[1], cur[1]);
            else
                ret.push_back(cur);
        }
        return ret;
    }
};
