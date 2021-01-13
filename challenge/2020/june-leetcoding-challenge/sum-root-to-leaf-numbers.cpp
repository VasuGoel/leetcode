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
    int sumNumbers(TreeNode* root) {
        return sumPaths(root, 0);
    }
    
    int sumPaths(TreeNode *root, int path) {
        if(!root)   
            return 0;
        if(!root->left and !root->right)
            return path*10 + root->val;
        
        path = path*10 + root->val;
        return sumPaths(root->left, path) + sumPaths(root->right, path);
    }
};
