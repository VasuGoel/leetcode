// O(n) time, O(1) space
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        // swap each nums[i] into right index with nums[0] = 1, nums[1] = 2, ... and so on. Ex: [3,1,3,4,3,2] -> [1,2,3,4,3,3]
        for(int i = 0; i < n; i++) {
            while(nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
        }
        // last element is guaranteed to be a duplicate
        return nums.back();
    }
};
