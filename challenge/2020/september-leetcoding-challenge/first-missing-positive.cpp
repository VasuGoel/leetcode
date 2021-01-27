// O(n) time, O(1) space
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // swap nums to correct indicies with nums[i] == nums[nums[i]-1]
        for(int i = 0; i < n; i++) {
            while(nums[i] > 0 and nums[i] <= n and nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
        }
        
        // return first positive integer not present in nums
        for(int i = 0; i < n; i++)
            if(nums[i] != i+1)
                return i+1;
        return n+1;
    }
};
