// O(n • logn) time, O(n) space
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> s;
        
        for(int i = 0; i < nums.size(); i++) {
            auto pos = s.lower_bound((long)nums[i]-t);
            if(pos != s.end() and *pos - nums[i] <= t)  return true;
            
            s.insert(nums[i]);
            if(i >= k)  s.erase(nums[i-k]);     // maintain set from nums[i-k, i]
        }
        return false;
    }
};

/*

Given, |nums[i] - nums[j]| ≤ t
    => -t ≤ nums[i] - nums[j] ≤ t
    => nums[i] >= nums[j] - t

This is similar to finding lower_bound(nums[j]-t) for nums[i], but this doesn't put an upper bound
on nums[i] and we need to also check |nums[i] - nums[j]| ≤ t, to make sure we're within bounds

*/
