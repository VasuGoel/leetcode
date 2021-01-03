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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return construct(preorder, i, NAN, NAN);
    }
    
    TreeNode *construct(vector<int> &preorder, int &i, double min, double max) {
        if(i == preorder.size() or (min != NAN and preorder[i] < min) or (max != NAN and preorder[i] > max))  
            return nullptr;
        
        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = construct(preorder, i, min, root->val);
        root->right = construct(preorder, i, root->val, max);
        return root;
    }
};
