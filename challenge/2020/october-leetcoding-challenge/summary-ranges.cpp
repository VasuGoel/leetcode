// O(n) time, O(1) space. Using two pointers;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        
        int n = nums.size(), l = 0, r;
        while(l < n) {
            r = l;
            while(r < n-1 and nums[r] == nums[r+1]-1)   r++;
            
            ret.push_back(l == r ? to_string(nums[l]) : to_string(nums[l]) + "->" + to_string(nums[r]));
            l = r+1;
        }
        return ret;
    }
};
