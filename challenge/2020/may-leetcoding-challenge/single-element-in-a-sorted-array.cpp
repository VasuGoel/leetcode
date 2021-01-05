// O(logn) time, O(1) space. Binary search.
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), lo = 0, hi = n-1, mid;
        
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if(mid % 2 == 0) {
                if(nums[mid] == nums[mid+1])    lo = mid + 2;
                else    hi = mid;
            }
            else {
                if(nums[mid] == nums[mid-1])    lo = mid + 1;
                else    hi = mid - 1;
            }
        }
        return nums[lo];
    }
};

/*

Intuition is that first occurrence of all duplicates will be at even indices (0, 2, 4, ...) in a sorted array with all elements present twice,
while second occurrence will be at odd indices (1, 3, 5, ...).
     
     0 1 2 3 4 5 6 7                                                                                                 0 1  2  3 4 5 6 7 8
Ex: [1,1,3,3,4,4,8,8], but for this problem a single element without duplicate is present and have to be found like [1,1, 2, 3,3,4,4,8,8], 
here first occurrence of 3 is present at odd index (i.e, 3) hence singleton element has to be present on left of this 3, otherwise right.

*/
