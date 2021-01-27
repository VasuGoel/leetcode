// DFS/Backtracking
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ret;
        dfs(candidates, target, 0, vector<int>()={}, ret);
        return ret;
    }
    
    void dfs(vector<int> &candidates, int target, int pos, vector<int> &path, vector<vector<int>> &ret) {
        if(target <= 0) {
            if(!target)     ret.push_back(path);
            return;
        }
        
        for(int i = pos; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i, path, ret);
            path.pop_back();
        }
    }
};
