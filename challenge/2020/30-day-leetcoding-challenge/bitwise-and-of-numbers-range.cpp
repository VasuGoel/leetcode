// keep shifting right until m and n are equal, and return either shifted left by same amount
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shifts = 0;
        
        while(m != n) {
            m >>= 1;
            n >>= 1;
            shifts++;
        }
        return m << shifts;
    }
};


// -------------------------------------------------------------------------------------––––––––


// from msb to lsb stop if m and n bits mismatch, while keep adding to res
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        
        for(int i = 31; i >= 0; i--) {
            if((m & (1 << i)) != (n & (1 << i)))    
                break;
            else    
                res |= (m & (1 << i));
        }
        return res;
    }
};
