// O(1) time and space
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        
        while(x or y) {
            res += (x & 1) ^ (y & 1);
            x >>= 1;
            y >>= 1;
        }
        return res;
    }
};


// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(1) time and space
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        
        for(int i = 0; i < 32; i++)
            if((x & (1 << i)) ^ (y & (1 << i)))
                res++;
        
        return res;
    }
};
