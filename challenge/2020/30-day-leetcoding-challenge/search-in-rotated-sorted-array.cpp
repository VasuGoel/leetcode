// O(logn) time, O(1) space, where n = nums length
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), lo = 0, hi = n-1, mid;
        
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            
            if(nums[mid] == target)     return mid;
            
            if(nums[lo] <= nums[mid]) {
                if(nums[lo] <= target and target <= nums[mid])   hi = mid;
                else    lo = mid+1;
            }
            else {
                if(nums[mid] <= target and target <= nums[hi])  lo = mid+1;
                else    hi = mid;
            }
        }
        return -1;
    }
};
