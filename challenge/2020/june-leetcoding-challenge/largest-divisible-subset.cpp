// O(n^2) time, O(n) space DP
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // sort nums to maintain order while checking if two numbers in nums are divisible
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), maxlen = 1, last = 0;
        vector<int> dp(n, 1), prev(n, -1), ret;
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 and dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1, prev[i] = j;
                
                if(dp[i] > maxlen) {
                    maxlen = dp[i];
                    last = i;
                }
            }
        }

        // build largest divisble subset
        for(int i = last; i >= 0; i = prev[i])
            ret.push_back(nums[i]);
        return ret;
    }
};

/*

dp[i] means max length of largest divisible subset upto index i.
prev[i] stores index of previous element in largest divisible subset.

*/
