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
    unordered_map<int, int> mp;
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        int res = 1;
        dfs(root, 1, 1, res);
        return res;
    }
    
    void dfs(TreeNode *root, uint32_t level, uint32_t i, int &res) {
        if(!root)   return;
        
        if(!mp.count(level))
            mp[level] = i;
        else
            res = max((uint32_t)res, i-mp[level]+1);
        
        dfs(root->left,  level+1, 2*i, res);
        dfs(root->right, level+1, 2*i+1, res);
    }
};


/*

We know that a binary tree can be represented by an array (assume the root begins from the position with index 1 in the array). If the index of a node is i, 
the indices of its two children are 2*i and 2*i + 1. The idea is to store the indices of leftmost node and rightmost node at each level and the width at each
level will then be (index of rightmost node) - (index of leftmost node) + 1. We can simply return the max among all levels.

Ex: Consider the binary tree [1,3,2,5,3,null,9]

           1
         /   \
        3     2         -> Original tree
       / \     \  
      5   3     9 

           1
         /   \          -> corresponding indices of each node
        2     3
       / \     \  
      4   5     7 

index       width at that level     max width from left subtree     max width from right subtree
4                   1                       0                               0  
5                   2                       0                               0
2                   1                       1                               2
7                   4                       0                               0
3                   2                       0                               4
1                   1                       2                               4

*/
