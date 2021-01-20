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

// Variation of Subarray Sum Equals to K on binary tree
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int,int> mp {{0, 1}};
        return dfs(root, sum, 0, mp);
    }
    
    int dfs(TreeNode *root, int &sum, int curSum, unordered_map<int,int> &mp) {
        if(!root)   return 0;
        
        int res = 0;
        
        curSum += root->val;
        if(mp.count(curSum - sum))     res += mp[curSum - sum];
        mp[curSum]++;
        
        res += dfs(root->left,  sum, curSum, mp) + dfs(root->right, sum, curSum, mp);
        
        mp[curSum]--;   // decrement is necessary to avoid counting it in sibling/cousin subtree
        return res;
    }
};
