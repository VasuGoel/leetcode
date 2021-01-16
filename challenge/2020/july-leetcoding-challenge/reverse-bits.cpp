// O(1) time and space.
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0, i = 0;
        
        while(n) {
            res |= ((n & 1) << (31-i));
            i++;
            n >>= 1;
        }
        return res;
    }
};
