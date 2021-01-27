// O(n) time, O(1) space. Two pointer approach.
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), res = 0, prod = 1, l = 0;
        
        for(int r = 0; r < n; r++) {
            prod *= nums[r];
            while(prod >= k and l <= r)
                prod /= nums[l++];
            
            res += r-l+1;
        }
        return res;
    }
};
