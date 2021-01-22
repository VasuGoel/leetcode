// O(n • logn) time, O(n) space. Binary search.
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        map<int,int> mp;
        
        // insert all start points (unique) in map (along with indices of interval)
        for(int i = 0; i < n; i++)  
            mp[intervals[i][0]] = i;
        
        // for each interval i find the first start point greater than equal to i's end point
        vector<int> ret (n, -1);
        for(int i = 0; i < n; i++) {
            auto pos = mp.lower_bound(intervals[i][1]);
            
            if(pos != mp.end())
                ret[i] = pos->second;
        }
        return ret;
    }
};
