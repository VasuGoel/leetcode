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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        if(!root)   return ret;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()) {
            int len = q.size();
            long n = len, sum = 0;
            
            while(len--) {
                auto cur = q.front(); q.pop();
                sum += cur->val;

                if(cur->left)   q.push(cur->left);
                if(cur->right)  q.push(cur->right);
            }
            ret.push_back((double)sum/n);
        }
        return ret;
    }
};
