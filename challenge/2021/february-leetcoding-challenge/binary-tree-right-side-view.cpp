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

// BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)   return {};
        vector<int> ret;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()) {
            int len = q.size();
            TreeNode *rightmost = nullptr;
            
            while(len--) {
                auto cur = q.front(); q.pop();
                
                rightmost = cur;
                if(cur->left)   q.push(cur->left);
                if(cur->right)  q.push(cur->right);
            }
            
            if(rightmost)   ret.push_back(rightmost->val);
        }
        return ret;
    }
};
