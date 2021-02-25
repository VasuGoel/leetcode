// O(n) time, O(1) space
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), maxi = INT_MIN, mini = INT_MAX, l = 0, r = 0;
        
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            if(nums[i] < maxi)  r = i;
        }
        
        for(int i = n-1; i >= 0; i--) {
            mini = min(mini, nums[i]);
            if(nums[i] > mini)  l = i;
        }
        return l < r ? r-l+1 : 0;
    }
};

/*

Find left and right boundary of required continuous subarray.

1. Iterate from left and keep track of max num so far, if smaller num than current max num is found mark it 'r'
2. Similarly, iterate from right and keep track of min num so far, if larger num than current min num is found mark it 'l'

For ex: [2, 6, 4, 8, 10, 9, 15]
            l            r      

*/
