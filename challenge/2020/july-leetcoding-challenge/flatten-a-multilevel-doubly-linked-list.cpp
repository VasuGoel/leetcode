/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

// O(n) time, O(1) space
class Solution {
public:
    Node* flatten(Node* head) {
        Node *cur = head;
        
        while(cur) {
            if(cur->child) {
                auto next = cur->next;
                auto ptr  = cur->child;
                
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr;
                    
                while(ptr->next)    ptr = ptr->next;
                ptr->next = next;
                if(ptr->next)   ptr->next->prev = ptr;
            }
            cur = cur->next;
        }
        return head;
    }
};
