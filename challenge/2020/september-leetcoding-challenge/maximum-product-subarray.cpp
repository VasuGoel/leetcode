// O(n) time, O(1) space
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res, maxprod, minprod;
        res = maxprod = nums[0];
        minprod = nums[0] < 0 ? nums[0] : 0;
        
        for(int i = 1; i < nums.size(); i++) {
            int maxp = max({nums[i], nums[i] * maxprod, nums[i] * minprod});
            int minp = min({nums[i], nums[i] * maxprod, nums[i] * minprod});
            
            maxprod = maxp;
            minprod = minp;
            res = max(res, maxprod);
        }
        return res;
    }
};
