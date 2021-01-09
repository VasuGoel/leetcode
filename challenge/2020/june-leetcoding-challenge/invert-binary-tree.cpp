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

// Iterative approach (stack based) - More scalable since it's not bound to application stack like recusive approach
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)   return root;
        
        stack<TreeNode *> s;
        s.push(root);
        
        while(!s.empty()) {
            auto cur = s.top(); s.pop();
            swap(cur->left, cur->right);
            
            if(cur->right)  s.push(cur->right);
            if(cur->left)   s.push(cur->left);
        }
        return root;
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// Recursive approach
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)   return root;
        
        auto l = root->left, r = root->right;
        root->left = invertTree(r);
        root->right = invertTree(l);
        return root;
    }
};
