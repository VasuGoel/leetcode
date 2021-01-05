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

// DFS
class Solution {
    TreeNode *px = nullptr, *py = nullptr;
    int dx = -1, dy = -1;
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, x, y, 0, root);
        return dx == dy and px != py;
    }
    
    void dfs(TreeNode *root, int x, int y, int depth, TreeNode *parent) {
        if(!root)   return;
        
        if(root->val == x)
            dx = depth, px = parent;
        else if(root->val == y)
            dy = depth, py = parent;
        
        dfs(root->left, x, y, depth+1, root);
        dfs(root->right, x, y, depth+1, root);
    }
};


// --------------------------------------------------------------------------------------------------


// BFS (level-order traversal)
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode *, int>> q;     // store pairs of node and parent value
        int parent = -1;
        q.push({root, parent});
        
        while(!q.empty()) {
            int len = q.size();
            
            while(len--) {
                auto cur = q.front(); q.pop();
                TreeNode *node = cur.first;
                
                // if potential cousin is found update 'parent' value
                if(node->val == x or node->val == y) {
                    // if we already found one potential cousin
                    if(parent != -1) {
                        // check if second potential cousin's parent value is different from first 'parent' value
                        return parent != cur.second;
                    }
                    parent = cur.second;
                }
                
                if(node->left)  q.push({node->left, node->val});
                if(node->right) q.push({node->right, node->val});
            }
            
            // if only one potential cousin is found in a level, return false (cousins cannot be in different levels)
            if(parent != -1)    return false;
        }
        return true;
    }
};
