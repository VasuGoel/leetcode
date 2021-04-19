// DP (based on coin change problem)
class Solution {    
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint32_t> dp(target+1);
        dp[0] = 1;
        
        for(int i = 1; i <= target; i++) {
            for(int num: nums) {
                if(i >= num)    
                    dp[i] += dp[i-num];
            }
        }
        return dp[target];
    }
};


// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// Memoized DFS
class Solution {
    unordered_map<int, int> cache;
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0)     return cache[0] = 1;
        if(cache.count(target))     return cache[target];
        
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(target >= nums[i]) {
                res += combinationSum4(nums, target - nums[i]);   
            }
        }
        return cache[target] = res;
    }
};

/*

So we know that target is the sum of numbers in the array. Imagine we only need one more number to reach target, 
this number can be any one in the array. So the # of combinations of target, comb[target] = sum(comb[target - nums[i]]), where 0 <= i < nums.length, and target >= nums[i].

In the example given, we can actually find the # of combinations of 4 with the # of combinations of 3(4 - 1), 2(4- 2) and 1(4 - 3). 
As a result, comb[4] = comb[4-1] + comb[4-2] + comb[4-3] = comb[3] + comb[2] + comb[1].
Then think about the base case. Since if the target is 0, there is only one way to get zero, which is using 0, we can set comb[0] = 1.

Follow up: 
The problem with negative numbers is that now the combinations could be potentially of infinite length. 
Think about nums = [-1, 1] and target = 1. We can have all sequences of arbitrary length that follow the patterns
-1, 1, -1, 1, ..., -1, 1, 1 and 1, -1, 1, -1, ..., 1, -1, 1 (there are also others, of course, just to give an example). 
So we should limit the length of the combination sequence, so as to give a bound to the problem.

*/
