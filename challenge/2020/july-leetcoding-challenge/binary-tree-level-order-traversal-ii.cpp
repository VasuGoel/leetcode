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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)   return {};
        deque<vector<int>> ret;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()) {
            int len = q.size();
            vector<int> level;
            
            while(len--) {
                auto cur = q.front(); q.pop();
                level.push_back(cur->val);
                
                if(cur->left)   q.push(cur->left);
                if(cur->right)  q.push(cur->right);
            }
            ret.push_front(level);
        }
        return {ret.begin(), ret.end()};
    }
};
