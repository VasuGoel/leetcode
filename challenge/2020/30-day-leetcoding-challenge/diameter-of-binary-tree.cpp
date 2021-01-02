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
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root).first;
    }
    
    // return pair of {diameter of tree, height of tree} at each node
    pair<int,int> dfs(TreeNode *root) {
        if(!root)   return {0, 0};
        
        auto ls = dfs(root->left);
        auto rs = dfs(root->right);
        
        // diameter of tree is max of {diameter of left subtree, diameter of right subtree, height of left subtree + height of right subtree}
        int diameter = max({ls.first, rs.first, ls.second + rs.second});
        // return pair {diameter of tree, height of tree}
        return {diameter, max(ls.second, rs.second) + 1};
    }
};
