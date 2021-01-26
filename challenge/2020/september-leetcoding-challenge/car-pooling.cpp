// O(n•logn) time, O(n) space
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;
        
        for(auto trip: trips)
            mp[trip[1]] += trip[0], mp[trip[2]] -= trip[0];
        
        for(auto e: mp)
            if((capacity -= e.second) < 0)
                return false;
        
        return true;
    }
};


/*

• Intuition: Track the change of customers in time order.

• Explanation:
- Save all time points and the change on current capacity
- Sort all the changes on the key of time points.
- Track the current capacity and return false if negative

*/


// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(d) time and space, where d = max value of trips[i][2] (end point)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> v(1001);
        
        for(auto trip: trips)
            v[trip[1]] += trip[0], v[trip[2]] -= trip[0];
        
        for(int i = 0; i <= 1000; i++)
            if((capacity -= v[i]) < 0)
                return false;
        
        return true;
    }
};
