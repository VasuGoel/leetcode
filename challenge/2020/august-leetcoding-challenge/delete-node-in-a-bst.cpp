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

// O(height of tree) time
class Solution {
public:
    // returns root after deleting 'key' from BST rooted at 'root'
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return nullptr;
        
        if(key < root->val)
            root->left  = deleteNode(root->left, key);
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        // we are at node with val == key (to be deleted)
        else {
            if(!root->left and !root->right)    return nullptr;     // has no children
            else if(!root->left )   root = root->right;             // only has right child
            else if(!root->right)   root = root->left;              // only has left child
            // node to be deleted has both left and right children
            else {
                root->val = getMin(root->right);
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }
    
    int getMin(TreeNode *root) {
        while(root->left)   root = root->left;
        return root->val;
    }
};

/*

Steps -
1. Recursively find the node that has the same value as the key, while setting the left/right nodes equal to the returned subtree
2. Once the node is found, have to handle the below 4 cases:
    • node doesn't have left or right - return null
    • node only has left subtree- return the left subtree
    • node only has right subtree- return the right subtree
    • node has both left and right - find the minimum value in the right subtree, set that value to the currently found node, then recursively delete the minimum value in the right subtree

*/
