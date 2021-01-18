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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int,int> indices;
        
        for(int i = 0; i < n; i++)   
            indices[inorder[i]] = i;
        
        int pos = n-1;
        return construct(indices, 0, n-1, postorder, pos);
    }
    
    TreeNode *construct(unordered_map<int,int> &indices, int l, int r, vector<int> &postorder, int &pos) {
        if(l > r)   return nullptr;
        
        TreeNode *root = new TreeNode(postorder[pos--]);
        root->right = construct(indices, indices[root->val]+1, r, postorder, pos);
        root->left  = construct(indices, l, indices[root->val]-1, postorder, pos);
        return root;
    }
};
