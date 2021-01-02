/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Search in the original tree, navigating in both original and cloned tree in same direction (works for duplicate values in binary tree)
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original)     return nullptr;
        if(original == target)   return cloned;     // ensures we land on target node, hence works with duplicate values present in tree

        auto ls = getTargetCopy(original->left, cloned->left, target);
        auto rs = getTargetCopy(original->right, cloned->right, target);

        return ls ? ls : rs;
    }
};
