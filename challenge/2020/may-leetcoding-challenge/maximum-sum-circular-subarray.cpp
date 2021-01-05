// O(n) time, O(1) space
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int prev = maxSubarraySum(A);
        if(prev <= 0)   return prev;    // if all elements are -ve or 0, return max subarray sum
        
        int total = 0;
        for(int &num: A) {
            total += num;
            num *= -1;
        }
        return max(prev, total + maxSubarraySum(A));
    }
    
    // usual kadane's algorithm to find max subarray sum
    int maxSubarraySum(vector<int> &nums) {
        int res = INT_MIN, sum = 0;
        for(int num: nums) {
            sum += num;
            res = max(res, sum);
            sum = max(sum, 0);
        }
        return res;
    }
};

/*

Intuition - We already know kadane's algorithm to find max subarray sum in normal array

In circular array, there are two cases -
Case 1. The first is that the subarray takes only a middle part, and we know how to find the max subarray sum.
Case 2. The second is that the subarray takes a part of head array and a part of tail array. We can transfer this case to the first one.
        The maximum result equals to the total sum minus the minimum subarray sum. Note: min subarray sum = max subarray sum of (-1 * array)
        Visual - https://assets.leetcode.com/users/motorix/image_1538888300.png

*/
