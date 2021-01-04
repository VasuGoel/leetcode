// O(1) time and space
class Solution {
public:
    int findComplement(int num) {
        int res = 0, i = 0;
        
        while(num) {
            res |= !(num & 1) << i++;
            num >>= 1;
        }
        return res;
    }
};
