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

// Inorder traversal traverses BST in ascending order
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        inorder(root, k, res);
        return res;
    }
    
    void inorder(TreeNode *root, int &k, int &res) {
        if(!root)   return;
        
        inorder(root->left, k, res);
        if(--k == 0)    res = root->val;
        inorder(root->right, k, res);
    }
};
