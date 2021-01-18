// O(n) time, O(1) space
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), lo = 0, hi = n-1, mid;
        
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if(nums[lo] < nums[hi])   return nums[lo];
            
            if(nums[lo] < nums[mid])
                lo = mid+1;
            else if(nums[lo] > nums[mid])
                hi = mid;
            else
                lo++;
        }
        return nums[lo];
    }
};


/*

This problem is different from part i, since it allows for duplicates in array. This will affect worst-case time complexity.
Suppose an array [0,1,1,1,1] is rotated to [1,0,1,1,1] and [1,1,1,0,1]. In these two cases, nums[l] == nums[m] == nums[r], but in the first case, 
the minimum is in the left while in the right in the second case. When all nums[l], nums[m] and nums[r] are equal, we will have no idea which half to move on. 
In this case, a linear search from l to r is necessary and the time complexity becomes O(n)

*/
