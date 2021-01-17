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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)   return {};
        int dir = 1;
        vector<vector<int>> ret;
        
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            int len = q.size();
            deque<int> level;
            
            while(len--) {
                auto cur = q.front(); q.pop();
                
                if(dir) 
                    level.push_back(cur->val);
                else    
                    level.push_front(cur->val);
                
                if(cur->left)   q.push(cur->left);
                if(cur->right)  q.push(cur->right);
            }
            dir ^= 1;
            ret.push_back({level.begin(), level.end()});
        }
        return ret;
    }
};
