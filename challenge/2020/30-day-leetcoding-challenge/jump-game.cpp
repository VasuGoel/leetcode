// O(n) time, O(1) space
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxind = 0;
        
        for(int i = 0; i < n; i++) {
            maxind = max(maxind, i + nums[i]);
            if(maxind >= n-1)   return true;
            if(i == maxind)     return false;
        }
        throw runtime_error("");
    }
};
