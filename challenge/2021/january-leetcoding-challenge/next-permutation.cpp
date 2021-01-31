// O(n) time, O(1) space
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), l = n-2, r = n-1;
        
        while(l >= 0 and nums[l] >= nums[l+1])  l--;
        if(l == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        while(r >= 0 and nums[r] <= nums[l])    r--;
        swap(nums[l], nums[r]);
        reverse(nums.begin()+l+1, nums.end());
    }
};

/*

        l     r
6 8 3   2 7 5 4 1
6 8 3   4 7 5 2 1   -> swap(nums[l], nums[r])
6 8 3   4 1 2 5 7   -> reverse numbers after l+1

*/
