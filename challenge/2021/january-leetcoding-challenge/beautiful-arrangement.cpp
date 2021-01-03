// typical backtracking, trying all possible arrangements
class Solution {
public:
    int countArrangement(int n) {
        return dfs(n, 1, bitset<32>(0)={});
    }
    
    int dfs(int n, int pos, bitset<32> &chosen) {
        if(pos == n+1)  return 1;
        int res = 0;
        
        for(int i = 1; i <= n; i++) {
            if(!chosen[i] and (i % pos == 0 or pos % i == 0)) {
                chosen[i] = 1;
                res += dfs(n, pos+1, chosen);
                chosen[i] = 0;
            }
        }
        return res;
    }
};
