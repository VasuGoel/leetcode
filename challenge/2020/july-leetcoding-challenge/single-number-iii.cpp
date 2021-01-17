// O(1) time and space
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // perform xor of all nums to get xor of required single numbers
        long x = accumulate(nums.begin(), nums.end(), 0, bit_xor());
        // find least significant bit that is set, in xor of required single numbers
        x &= -x;
        
        vector<int> ret(2);
        // divide nums in two groups, one where above bit is set and other where it's not
        for(int num: nums) {
            if(num & x)
                ret[0] ^= num;
            else
                ret[1] ^= num;
        }
        return ret;
    }
};
