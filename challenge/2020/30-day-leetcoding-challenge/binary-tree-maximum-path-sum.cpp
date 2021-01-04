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
    int maxPathSum(TreeNode* root) {
        int max_element = INT_MIN;
        int res = dfs(root, max_element).first;
        // if max path sum equals 0 (means all elements in tree are -ve), return max element in tree
        return !res ? max_element : res;
    }
    
    // return pair of {max path sum, max depth sum (or max sum along deepest path from that node to leaf)}
    pair<int,int> dfs(TreeNode *root, int &max_element) {
        if(!root)   return {0, 0};
        
        max_element = max(max_element, root->val);
        
        auto ls = dfs(root->left, max_element);
        auto rs = dfs(root->right, max_element);
        
        // max path sum at any node is max of left and right subtree and also the deepest path sum of left and right subtree (both maximized with 0, to avoid adding -ve node to sum) plus current node value
        int maxpathsum = max({ls.first, rs.first, max(ls.second, 0) + max(rs.second, 0) + root->val});
        // at each node return max path sum found upto that node and deepest path sum (maximized with 0 to avoid negative node in deepest path)
        return {maxpathsum, max({ls.second, rs.second, 0}) + root->val};
    }
};
