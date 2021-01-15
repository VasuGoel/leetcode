// O(n^2) time, O(1) space. Using 3-pointers.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<vector<int>> ret;
        
        for(int i = 0; i < n-2; i++) {
            if(i != 0 and nums[i] == nums[i-1])     continue;
            
            int l = i+1, r = n-1, target = -nums[i];
            
            while(l < r) {
                if(nums[l] + nums[r] == target) {
                    ret.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;
                    
                    while(l < r and nums[l] == nums[l-1])   l++;
                    while(l < r and nums[r] == nums[r+1])   r--;
                }
                else if(nums[l] + nums[r] < target)
                    l++;
                else
                    r--;
            }
        }
        return ret;
    }
};
