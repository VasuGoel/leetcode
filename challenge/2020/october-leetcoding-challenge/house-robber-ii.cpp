// O(n) time and space
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];
        
        return max(houseRobber(nums, 0, n-2), houseRobber(nums, 1, n-1));
    }
    
    int houseRobber(vector<int> &nums, int l, int r) {
        vector<int> dp(nums.size());
        
        for(int i = l; i <= r; i++)
            dp[i] = max((i > 0 ? dp[i-1] : 0), nums[i] + (i > 1 ? dp[i-2] : 0));
        
        return dp[r];
    }
};

/*

This problem can simply be decomposed into two House Robber problems.
Suppose there are n houses, since house 0 and n - 1 are now neighbors, we cannot rob them together and thus the solution is now the maximum of

• Rob houses 0 to n - 2
• Rob houses 1 to n - 1

*/
