/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)   return "null";
        return to_string(root->val) + ',' + serialize(root->left) + ',' + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return construct(ss);
    }
    
    TreeNode *construct(istringstream &ss) {
        string token;
        getline(ss, token, ',');
        
        if(token == "null")     return nullptr;
        
        TreeNode *root = new TreeNode(stoi(token));
        root->left  = construct(ss);
        root->right = construct(ss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
