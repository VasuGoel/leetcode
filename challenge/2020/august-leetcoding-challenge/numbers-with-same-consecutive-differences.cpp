// DFS. O(n • 2^n) time
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ret;
        for(int i = 1; i <= 9; i++)
            dfs(n-1, k, i, ret);
        return ret;
    }
    
    void dfs(int n, int &k, int cur, vector<int> &ret) {
        if(!n) {
            ret.push_back(cur);
            return;
        }
        
        for(int i = 0; i <= 9; i++)
            if(abs(cur%10 - i) == k)
                dfs(n-1, k, cur*10 + i, ret);
    }
};
