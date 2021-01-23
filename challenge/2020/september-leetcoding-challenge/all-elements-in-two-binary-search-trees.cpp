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

// O(n) time and space, where n = total number of nodes in both trees
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        // inorder traversal of BST produces sorted sequence
        vector<int> p, q, ret;
        inorder(root1, p);
        inorder(root2, q);
        
        // merge two sorted arrays
        int i = 0, j = 0;
        while(i < p.size() and j < q.size())
            ret.push_back(p[i] < q[j] ? p[i++] : q[j++]);
        while(i < p.size())    ret.push_back(p[i++]);
        while(j < q.size())    ret.push_back(q[j++]);
        return ret;
    }
    
    void inorder(TreeNode *root, vector<int> &ret) {
        if(!root)   return;
        
        inorder(root->left, ret);
        ret.push_back(root->val);
        inorder(root->right, ret);
    }
};
