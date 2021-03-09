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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) {
            TreeNode *ret = new TreeNode(v);
            ret->left = root;
            return ret;
        }
        dfs(root, v, d-1);
        return root;
    }

    void dfs(TreeNode *root, int v, int d) {
        if(!root)   return;
        
        if(d == 1) {
            auto l = root->left;
            root->left = new TreeNode(v);
            root->left->left = l;
            
            auto r = root->right;
            root->right = new TreeNode(v);
            root->right->right = r;
        }
        
        dfs(root->left,  v, d-1);
        dfs(root->right, v, d-1);
    }
};
