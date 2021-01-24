class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        dfs(k, n, 1, vector<int>()={}, ret);
        return ret;
    }
    
    void dfs(int k, int n, int cur, vector<int> &path, vector<vector<int>> &ret) {
        if(!k) {
            if(!n)  ret.push_back(path);
            return;
        }
        
        for(int i = cur; i <= 9; i++) {
            path.push_back(i);
            dfs(k-1, n-i, i+1, path, ret);
            path.pop_back();
        }
    }
};
