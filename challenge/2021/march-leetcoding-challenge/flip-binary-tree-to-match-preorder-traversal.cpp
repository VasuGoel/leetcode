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

// O(n) time, O(height) space
class Solution {
    int i = 0;
    vector<int> ret;
    
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        return dfs(root, voyage) ? ret : vector<int>{-1};
    }
    
    bool dfs(TreeNode *root, vector<int> &voyage) {
        if(!root)   return true;
        if(root->val != voyage[i++])    return false;
        if(root->left and root->left->val != voyage[i]) {
            ret.push_back(root->val);
            return dfs(root->right, voyage) and dfs(root->left, voyage);
        }
        return dfs(root->left, voyage) and dfs(root->right, voyage);
    }
};
