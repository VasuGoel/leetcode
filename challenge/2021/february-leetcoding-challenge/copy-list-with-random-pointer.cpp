/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// O(n) time and space. Using hashmap.
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> copies;
        
        Node *ret = nullptr, **pp = &ret;
        
        for(auto it = head; it ; it = it->next) {
            *pp = new Node(it->val);
            copies[it] = *pp;
            pp = &((*pp)->next);
        }
        
        for(auto it = head, cur = ret; it ; it = it->next, cur = cur->next) {
            if(it->random)
                cur->random = copies[it->random];
        }
        return ret;
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(n) time, O(1) space
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return nullptr;
        
        // iterate over list and create duplicate node and append after self for each node
        auto it = head;
        while(it) {
            Node *dup = new Node(it->val);
            dup->next = it->next;
            it->next = dup;
            it = it->next->next;
        }
        
        // connect random pointers for copied nodes
        it = head;
        while(it) {
            if(it->random)
                it->next->random = it->random->next;
            it = it->next->next;
        }
        
        // detach main list from copied list
        it = head;
        auto ret = head->next, cur = ret;
        while(it) {
            it->next = it->next->next;
            if(cur->next)
                cur->next = cur->next->next;
            
            it = it->next;
            if(it)  cur = it->next;
        }
        return ret;
    }
};
