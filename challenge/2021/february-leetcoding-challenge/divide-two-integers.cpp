// O(1) time and space
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN and divisor == -1)
            return INT_MAX;
        
        long numer = abs(dividend), deno = abs(divisor), res = 0;
        int sign  = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        
        while(numer >= deno) {
            long temp = deno, m = 1;
            while(temp << 1 <= numer) {
                temp <<= 1;
                m <<= 1;
            }
            numer -= temp;
            res += m;
        }
        return sign * res;
    }
};
