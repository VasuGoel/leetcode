// O(n) time and space
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())    return 0;
        int n = nums.size();
        vector<int> dp(n);
        
        for(int i = 0; i < n; i++)
            dp[i] = max((i > 0 ? dp[i-1] : 0), nums[i] + (i > 1 ? dp[i-2] : 0));
        
        return dp[n-1];
    }
};

/*

dp[i] means max profit upto house i.

At each house, we can either choose to not rob it and take max profit upto previous house, or rob it and
take its amount and max profit from previous to previous house (cannot rob consecutive houses)

*/
