// O(n) time and space
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0, res = 0;
        
        // search from msb to lsb and find out for each bit are there at least two numbers with different values
        for(int i = 31; i >= 0; i--) {
            // masks grows as 1000...., 1100...., 1110...., 1111.... (consists of bits considered so far since msb)
            mask |= (1 << i);
            
            // store prefixes of each number and discard right i bits
            unordered_set<int> s;
            for(int num: nums)
                s.insert(num & mask);

            // find if there are two nums with different ith bit, if yes, the new maximum should be previous maximum with set bit at ith position, which is the 'temp'
            // and two prefixes 'x' and 'y' must satisfy, x ^ y = temp. Since, x ^ y = temp => y = x ^ temp. Thus, using this we can find if such x and y exist in hashset
            int temp = res | (1 << i);
            for(int x: s) {
                if(s.count(x ^ temp))
                    res |= (1 << i);
            }
        }
        return res;
    }
};

/*

This algorithm's idea is:
To iteratively determine what would be each bit of the final result from left to right. And it narrows down the candidate group iteration by iteration. 
e.g. assume input are a,b,c,d,...z, 26 integers in total. In first iteration, if you found that a, d, e, h, u differs on the MSB (most significant bit), so you are sure your final result's MSB is set. 
Now in second iteration, you try to see if among a, d, e, h, u there are at least two numbers make the 2nd MSB differs, if yes, then definitely, the 2nd MSB will be set in the final result. 
And maybe at this point the candidate group shinks from a,d,e,h,u to a, e, h. Implicitly, every iteration, you are narrowing down the candidate group, but you don't need to track how the group is shrinking, 
you only cares about the final result.

Example: Given [14, 11, 7, 2], which in binary are [1110, 1011, 0111, 0010].
Since the MSB is 3, let's start from i = 3 for simplicity.

i = 3, set = {1000, 0000}, max = 1000
i = 2, set = {1100, 1000, 0100, 0000}, max = 1100
i = 1, set = {1110, 1010, 0110, 0010}, max = 1100
i = 0, set = {1110, 1011, 0111, 0010}, max = 1100

*/
