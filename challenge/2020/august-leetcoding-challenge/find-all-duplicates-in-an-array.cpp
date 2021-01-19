// O(n) time, O(1) space
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            while(nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
        
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i+1)
                ret.push_back(nums[i]);
        }
        return ret;
    }
};
