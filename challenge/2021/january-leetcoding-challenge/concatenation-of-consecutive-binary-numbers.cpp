// O(n) time and space
class Solution {
public:
    int concatenatedBinary(int n) {
        int res = 1;
        const int mod = 1e9+7;
        
        for(int i = 2; i <= n; i++) {
            int pos = log2(i);
            
            for(int b = pos; b >= 0; b--) {
                res <<= 1;
                res = (res | ((i & (1 << b)) ? 1 : 0)) % mod;
            }
        }
        return res;
    }
};
