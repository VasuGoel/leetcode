// O(n) time and space
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int ak = INT_MIN;
        
        for(int i = nums.size()-1; i >= 0; i--) {
            if(nums[i] < ak)     return true;
            
            while(!s.empty() and nums[i] > s.top()) {
                ak = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};

/*

We have to find a subsequence ai, aj, ak, where i < j < k and ai < ak < aj, in an array 'nums'.
For ex: nums = [3, 1, 4, 2] -> the subsequence [1, 4, 2] is a valid 132 pattern.

Starting from right-most num, we should try to keep the value of middle 'aj' as large as possible, and 'ak' should be next to largest
and we can keep comparing (each number as 'ai') < ak and since ak < aj we have a valid triplet ai < ak < aj.

We can use a stack to maintain sorted stack of decreasing numbers. Each time before pushing a new number, we can pop out all smaller numbers 
from stack and subsequently assign next popped element as 'ak'.

Example:
i = 6, nums = [ 9, 11, 8, 9, 10, 7, 9 ], 'ai' candidate = 9, 'ak' candidate = None, Stack = Empty
i = 5, nums = [ 9, 11, 8, 9, 10, 7, 9 ], 'ai' candidate = 7, 'ak' candidate = None, Stack = [9]
i = 4, nums = [ 9, 11, 8, 9, 10, 7, 9 ], 'ai' candidate = 10, 'ak' candidate = None, Stack = [9,7]
i = 3, nums = [ 9, 11, 8, 9, 10, 7, 9 ], 'ai' candidate = 9, 'ak' candidate = 9, Stack = [10]
i = 2, nums = [ 9, 11, 8, 9, 10, 7, 9 ], 'ai' candidate = 8, 'ak' candidate = 9, Stack = [10,9] We have 8<9, sequence (8,10,9) found!

*/
