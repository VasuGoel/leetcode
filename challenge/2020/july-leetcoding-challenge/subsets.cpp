// O(2^n) time, O(1) space. Usual dfs/backtracking.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        dfs(nums, 0, vector<int>() = {}, ret);
        return ret;
    }
    
    void dfs(vector<int> &nums, int pos, vector<int> &path, vector<vector<int>> &ret) {
        ret.push_back(path);
        
        if(pos == nums.size())  
            return;
        
        for(int i = pos; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, i+1, path, ret);
            path.pop_back();
        }
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(n • 2^n) time, O(n) space. Using bit-masking.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        
        for(int i = 0; i < (1 << n); i++) {
            vector<int> subset;
            for(int b = 0; b < n; b++)
                if(i & (1 << b))    subset.push_back(nums[b]);
            
            ret.push_back(subset);
        }
        return ret;
    }
};
