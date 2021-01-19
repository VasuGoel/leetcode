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
        for(auto &x: mp) {
            vector<int> level;
            for(auto &y: x.second)
                level.insert(level.begin(), y.second.begin(), y.second.end());

            ret.push_back(level);
        }
        return ret;
    }
    
    void dfs(TreeNode *root, int x, int y) {
        if(!root)   return;
        
        mp[x][y].insert(root->val);
        
        dfs(root->left , x-1, y-1);
        dfs(root->right, x+1, y-1);
    }
};
