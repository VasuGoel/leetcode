/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// Recursive
class Solution {
    vector<int> ret;

public:
    vector<int> preorder(Node* root) {
        dfs(root);
        return ret;
    }
    
    void dfs(Node *root) {
        if(!root)   return;
        
        ret.push_back(root->val);
        for(auto child: root->children)     
            dfs(child);
    }
};


// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// Iterative (Push all children of cur node in stack, in reverse order)
class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root)   return {};
        vector<int> ret;
        stack<Node *> s;
        s.push(root);
        
        while(!s.empty()) {
            auto cur = s.top(); s.pop();
            ret.push_back(cur->val);
            
            for(auto itr = cur->children.rbegin(); itr != cur->children.rend(); itr++)
                s.push(*itr);
        }
        return ret;
    }
};
