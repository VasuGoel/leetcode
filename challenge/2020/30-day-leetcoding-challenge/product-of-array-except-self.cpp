// O(n) time, O(1) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), prefix = 1, suffix = 1;
        vector<int> ret;
        
        for(int num: nums)  ret.push_back(prefix *= num);
        
        for(int i = n-1; i >= 0; i--) {
            ret[i] = (i ? ret[i-1] : 1) * suffix;
            suffix *= nums[i];
        }
        
        return ret;
    }
};
