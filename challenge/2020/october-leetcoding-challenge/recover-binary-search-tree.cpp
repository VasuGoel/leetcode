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

// Find 2 nodes that violate ascending order of inorder traversal, and swap them
class Solution {
    TreeNode *ptr1 = nullptr, *ptr2 = nullptr, *prev = nullptr;
    
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(ptr1->val, ptr2->val);
    }
    
    void inorder(TreeNode *root) {
        if(!root)   return;
        
        inorder(root->left);
        
        if(!ptr1 and prev and root->val < prev->val)
            ptr1 = prev;
        if(ptr1 and root->val < prev->val)
            ptr2 = root;
        
        prev = root;
        
        inorder(root->right);
    }
};
