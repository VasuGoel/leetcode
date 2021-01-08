// O(n) time and space DP
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num + 1);
        
        for(int i = 1; i <= num; i++) {
            ret[i] = ret[i >> 1] + (i & 1);
        }
        return ret;
    }
};

/*

num     binary      count
0       000         0
1       001         1
2       010         1
3       011         2
4       100         1
5       101         2
6       110         2
7       111         3

Intuition - 
Odd nums have last bit (lsb) as 1, while 0 for even nums

Observation - 
No. of set bits in 'num' = no. of set bits in 'num' right shifted by 1 (or divided by 2) + 1 (if num is odd)

*/
