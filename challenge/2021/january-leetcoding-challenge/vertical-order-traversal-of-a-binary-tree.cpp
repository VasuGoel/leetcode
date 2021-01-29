/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    map<int, map<int, set<int>>> mp;
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        
        vector<vector<int>> ret;
        for(auto x: mp) {
            auto y = x.second;
            
            vector<int> v;
            for(auto it = y.rbegin(); it != y.rend(); it++)
                v.insert(v.end(), it->second.begin(), it->second.end());
            
            ret.push_back(v);
        }
        return ret;
    }
    
    void dfs(TreeNode *root, int i, int j) {
        if(!root)   return;
        
        mp[i][j].insert(root->val);
        dfs(root->left , i-1, j-1);
        dfs(root->right, i+1, j-1);
    }
};
