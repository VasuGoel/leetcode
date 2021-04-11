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

// Typical DFS
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int d = depth(root);
        return !root ? 0 : sumAtDepth(root, d, 1);
    }
    
    int depth(TreeNode *root) {
        return !root ? 0 : 1 + max(depth(root->left), depth(root->right));
    }
    
    int sumAtDepth(TreeNode *root, int d, int level) {
        if(!root)
            return 0;
        if(level == d)
            return root->val;
            
        return sumAtDepth(root->left, d, level+1) + sumAtDepth(root->right, d, level+1);
    }
};
