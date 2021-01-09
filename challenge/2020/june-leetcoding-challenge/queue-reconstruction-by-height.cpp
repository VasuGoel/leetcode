// O(n • logn) time, O(n) space
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // sort people based on decreasing height and increasing offset (when height ties)
        sort(people.begin(), people.end(), [&](auto &a, auto &b) -> bool {
            return a[0] > b[0] or (a[0] == b[0] and a[1] < b[1]);
        });
        
        // from sorted list of people keep inserting people with correct offsets
        vector<vector<int>> ret;
        for(auto &p: people)
            ret.insert(ret.begin() + p[1], p);
        return ret;
    }
};
