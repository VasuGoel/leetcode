class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        auto lb = lower_bound(nums.begin(), nums.end(), target);
        if(lb == nums.end() || *lb != target)    return {-1, -1};
        
        auto ub = upper_bound(nums.begin(), nums.end(), target);
        int l = lb-nums.begin(), u = ub-nums.begin()-1;
        return {l, u};
    }
};
