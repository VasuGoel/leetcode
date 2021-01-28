// O(1) time and space
class Solution {
public:
    int bitwiseComplement(int N) {
        if(!N)  return 1;
        int res = 0, i = 0;
        
        while(N) {
            res |= (!(N & 1)) << i;
            i++;
            N >>= 1;
        }
        return res;
    }
};
