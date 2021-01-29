/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// DFS
class Solution {
    unordered_map<Node *, Node *> mp;
    
public:
    Node* cloneGraph(Node* node) {
        if(!node)   return node;
        
        if(mp.count(node))
            return mp[node];
        
        mp[node] = new Node(node->val);
        for(auto nei: node->neighbors)
            mp[node]->neighbors.push_back(cloneGraph(nei));
        
        return mp[node];
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)   return node;
        
        queue<Node *> q;
        q.push(node);

        unordered_map<Node *, Node *> mp;
        mp[node] = new Node(node->val);
        
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                auto cur = q.front(); q.pop();
                
                for(auto nei: cur->neighbors) {
                    if(!mp.count(nei)) {
                        q.push(nei);
                        mp[nei] = new Node(nei->val);
                    }
                    mp[cur]->neighbors.push_back(mp[nei]);
                }
            }
        }
        return mp[node];
    }
};
