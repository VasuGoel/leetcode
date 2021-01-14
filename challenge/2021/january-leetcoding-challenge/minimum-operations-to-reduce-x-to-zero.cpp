// O(n) time and space. Similar to Subarray Sum Equals to K.
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), target = -x;
        for(int num: nums)  target += num;
        
        if(!target)     return n;
        
        int sum = 0, res = INT_MIN;
        unordered_map<int, int> mp {{0, -1}};
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            
            if(mp.count(sum-target))
                res = max(res, i - mp[sum-target]);
            
            mp[sum] = i;
        }
        return res != INT_MIN ? n-res : -1;
    }
};

/*

• Naive solution is DFS + memoization, but that's too slow
• If an answer exists for above problem, then there is a subarray in the middle of original array whose sum is == totalSum - x
• If we want to minimize our operations, then we should maximize the length of the middle subarray
    • The question then becomes, find the longest subarray with sum == totalSum - x
    • This is very similar to problem, Subarray Sum Equals to K

Visual - https://assets.leetcode.com/users/images/bf560734-2107-4a1b-811a-f3dd6d54c6e6_1605413025.6626496.png

*/
