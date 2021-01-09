// O(logn) time, O(1) space. Find lower bound using binary search.
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1, mid;
        
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            
            if(nums[mid] < target)
                lo = mid+1;
            else
                hi = mid-1;
        }
        return lo;
    }
};


// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(logn) time, O(1) space
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
